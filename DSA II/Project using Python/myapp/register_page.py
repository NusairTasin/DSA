from tkinter import Frame, Label, Button, Entry, StringVar

class RegisterPage(Frame):
    def __init__(self, parent, controller):
        super().__init__(parent)
        
        # Add frame title label
        self.title_label = Label(self, text="Registration Page", font=("Arial", 14))
        self.title_label.pack(pady=20)

        print("Register page initialized")

        # Example entry fields and buttons
        self.user_name_label = Label(self, text="Username:")
        self.user_name_label.pack()

        self.user_name_entry = Entry(self)
        self.user_name_entry.pack()

        self.password_label = Label(self, text="Password:")
        self.password_label.pack()

        self.password_entry = Entry(self, show="*")
        self.password_entry.pack()

        # Login button
        login_button = Button(
            self,
            text="Login",
            command=lambda: controller.show_frame("login")
        )
        login_button.pack(pady=10)

    def close(self):
        self.title_label.destroy()
