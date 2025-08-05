# 📞 Telephone Book App (with Login & Registration) - C++

This is a simple console-based C++ application that simulates a telephone book system with basic **user login/registration** features. It allows users to securely register and manage their personal contact list.

---

## 🔧 Features

✅ User Registration  
✅ User Login  
✅ Create New Contact  
✅ View All Contacts  
✅ Edit Existing Contact  
✅ Delete Contact  
✅ Search Contact by Name  

---

## 🗂️ File Structure

- `main.cpp`: Contains the full application code.
- `users.txt`: Stores registered users' usernames and passwords.

---

## 🧑‍💻 How It Works

### 1. **Login/Register System**
- On launch, the user is asked to either **Register** or **Login**.
- Credentials are stored in a file named `users.txt`.
- After successful login, users can access the contact management menu.

### 2. **Telephone Book Functionality**
- Once logged in, users can:
  - **Create** new contacts by providing name, phone number, and email.
  - **View** all saved contacts.
  - **Edit** existing contacts by name.
  - **Delete** a contact by name.
  - **Search** for a contact by name.

---

## 🚀 How to Run

### Using any C++ compiler (like g++, Code::Blocks, Dev C++, etc):

### 📌 Compile:
```bash
g++ main.cpp -o telephonebook
