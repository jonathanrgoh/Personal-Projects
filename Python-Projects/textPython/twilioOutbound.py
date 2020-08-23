# Download the helper library from https://www.twilio.com/docs/python/install
from twilio.rest import Client


# Your Account Sid and Auth Token from twilio.com/console
# DANGER! This is insecure. See http://twil.io/secure
account_sid = 'AC6dc9e9b637d287ea1728213e6a59c105'
auth_token = '5ac28034c95db0ae3b9ca5b3f551a3d9'
client = Client(account_sid, auth_token)

message = client.messages \
                .create(
                     body="Watsup Jon",
                     from_='+1',
                     to='+12146766529'
                 )

print(message.sid)