from spleeter.separator import Separator

def extract_mr_track(audio_file_path, output_path):
    separator = Separator('spleeter:2stems')
    separator.separate_to_file(audio_file_path, output_path)

audio_file_path = 'your_music_video.mp3'  # 분리할 뮤직 비디오 파일 경로
output_path = 'output_path'  # MR 트랙을 저장할 경로

extract_mr_track(audio_file_path, output_path)
