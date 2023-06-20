from pytube import YouTube
link = input("Enter a youtube video's URL:\n")
yt = YouTube(link)
yt.streams.filter(only_audio=True).first().download()
