from gtts import gTTS
text = "This is my first text to speech conversion using gTTS library in Python."

tts = gTTS(text=text, lang='en')
tts.save("Text2speech.mp3")

print("Text to speech conversion completed. The audio file is saved as 'Text2speech.mp3'.")