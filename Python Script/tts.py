from ibm_watson import TextToSpeechV1
from ibm_cloud_sdk_core.authenticators import IAMAuthenticator

authenticator = IAMAuthenticator('0HE1EXoPggPLiwdq6jbLkw7qJuBkSilP8TYOvNK7XXpk')
text_to_speech = TextToSpeechV1(
    authenticator=authenticator
)

text_to_speech.set_service_url('https://api.eu-de.text-to-speech.watson.cloud.ibm.com/instances/e24ca6f6-496b-463b-b56f-4a0e79e76362')

with open('hello_world.wav', 'wb') as audio_file:
    audio_file.write(
        text_to_speech.synthesize(
            "Hi Swathi",
            voice='en-US_AllisonV3Voice',
            accept='audio/wav'        
        ).get_result().content)
