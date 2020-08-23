from guizero import App, Text, TextBox, PushButton, Slider, Picture

app = App(title="Hello World")

#Function Definitions Go Here
def say_my_name():
    welcome_message.value = "Hello " + my_name.value

def change_text_size(slider_value):
    welcome_message.size = slider_value





#Widgets Go Here
welcome_message = Text(app, text="Welcome to my app", size=40, font="Times New Roman", color="lightblue")

my_name = TextBox(app)

update_text = PushButton(app, command=say_my_name, text="Display my name")

text_size = Slider(app, command=change_text_size, start=10, end=80)

my_cat = Picture(app, image="comp.gif")  #picture needs to be in gif format





app.display()