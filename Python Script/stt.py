from os.path import join, dirname
import json
from ibm_watson import SpeechToTextV1
from ibm_cloud_sdk_core.authenticators import IAMAuthenticator

authenticator = IAMAuthenticator('j9h6e6YDj8jXPddQhRURKCXPZgbtLRjkMOjH6AT8H9xP')
speech_to_text = SpeechToTextV1(
    authenticator=authenticator
)

speech_to_text.set_service_url('https://api.eu-de.speech-to-text.watson.cloud.ibm.com/instances/52a21d3c-1687-4e55-9c02-f7e9b8ae0fe2')

with open(join(dirname(__file__), './.', 'hello_world.wav'),
               'rb') as audio_file:
    speech_recognition_results = speech_to_text.recognize(
        audio=audio_file,
        content_type='audio/wav',
    ).get_result()
print(json.dumps(speech_recognition_results, indent=2))
