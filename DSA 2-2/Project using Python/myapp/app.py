import tkinter as tk
from tkinter import Frame, Label, Button, Entry, StringVar

class App:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Bangladesh Police")
        self.root.geometry("800x600")

        # Frame Holder
        self.container = tk.Frame(self.root)
        self.container.pack(fill="both", expand=True)

        # Initialize frames with registration as the first page
        self.frames = {
            "register": None,
            "login": None
        }

        # Show the registration frame by default
        self.show_frame("register")

    def show_frame(self, page_name):
        """Show a frame for the given page name."""
        if isinstance(page_name, str) and (page_name in ["register", "login"]):
            frame = self.frames[page_name]
            if frame is None:
                # Destroy all frames except current
                for widget in self.container.find_all():
                    if widget != frame:
                        widget.destroy()
            frame.tkraise()

    def destroy_frame(self, page_name):
        """Destroy a frame of the given page name."""
        if isinstance(page_name, str) and (page_name in ["register", "login"]):
            if self.frames[page_name] is not None:
                self.frames[page_name].destroy()



# mydb = mysql.connector.connect(
#     host="localhost",
#     user="nusair",
#     password="nusairtasin",
#     database="mydatabase"
# )
# mycursor = mydb.cursor()
# query = ""
# val=("John", "Highway 21")
# mycursor.execute(query, val)
# mydb.commit()
# # for x in mycursor:
# #     print(x)
# root = tk.Tk()
# root.geometry("800x600")
# root.title(
#     'Hello World'
# )
# def on_submit() :
#     user_name=usern.get()
#     password=passw.get()
#     result_label.config(text=f"You have entered: {user_name}")
# label = tk.Label(root, text="Welcome to Bangladesh Police Case Portal", cursor="mouse")
# label.pack()
# # User_name input
# usern = tk.Entry(root, width=30)
# usern.pack(pady=5)

# #Password input
# passw = tk.Entry(root, width=30)
# passw.pack(pady=5)

# #Submit-button
# submit_button=tk.Button(root, text="Submit", command=on_submit)
# submit_button.pack()

# #Result-label
# result_label=tk.Label(root, text="")
# result_label.pack()

# root.mainloop()
