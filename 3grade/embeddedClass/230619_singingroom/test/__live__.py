import pyaudio
import numpy as np

# 오디오 파라미터 설정
CHUNK = 1024  # 한 번에 읽을 오디오 프레임 크기
FORMAT = pyaudio.paInt16  # 오디오 포맷
CHANNELS = 1  # 마이크 채널 수
RATE = 44100  # 샘플링 속도 (Hz)

# PyAudio 객체 생성
p = pyaudio.PyAudio()

# 오디오 스트림 열기
stream = p.open(format=FORMAT,
                channels=CHANNELS,
                rate=RATE,
                input=True,
                output=True,
                frames_per_buffer=CHUNK)

# 오디오 입력 및 출력 처리
while True:
    data = stream.read(CHUNK)
    audio = np.frombuffer(data, dtype=np.int16)
    stream.write(data)
