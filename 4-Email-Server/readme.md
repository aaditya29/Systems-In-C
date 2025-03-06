# MailServer in C

## How a Mail Server Works

A mail server works by handling the sending, receiving, and storage of emails. Here is a detailed explanation of the process:

### 1. Sending Email

When a user sends an email, the email client (e.g., Outlook, Gmail) connects to the mail server using the Simple Mail Transfer Protocol (SMTP). The steps involved are:

- The email client connects to the SMTP server.
- The client sends the sender's and recipient's email addresses, the subject, and the body of the email to the SMTP server.
- The SMTP server processes the email and determines the recipient's domain.

### 2. Relaying Email

If the recipient's domain is different from the sender's domain, the SMTP server relays the email to the recipient's mail server. The steps involved are:

- The SMTP server looks up the recipient's domain's Mail Exchange (MX) record in the Domain Name System (DNS).
- The SMTP server connects to the recipient's SMTP server.
- The email is transferred to the recipient's SMTP server.

### 3. Receiving Email

Once the recipient's SMTP server receives the email, it stores the email in the recipient's mailbox. The steps involved are:

- The SMTP server stores the email in the recipient's mailbox on the mail server.
- The recipient's email client connects to the mail server using either the Post Office Protocol (POP3) or the Internet Message Access Protocol (IMAP).
- The email client retrieves the email from the mail server and displays it to the recipient.

### 4. Storing Email

Mail servers store emails in mailboxes, which are directories or files on the server. The storage process involves:

- Organizing emails in folders or directories based on user preferences.
- Maintaining metadata such as timestamps, sender and recipient information, and email status (read/unread).

### Protocols Used

- **SMTP (Simple Mail Transfer Protocol):** Used for sending emails.
- **POP3 (Post Office Protocol 3):** Used for retrieving emails from the server. It downloads emails to the client's device and usually deletes them from the server.
- **IMAP (Internet Message Access Protocol):** Used for retrieving emails from the server. It allows multiple devices to access the same mailbox, keeping emails on the server.

### Security

Mail servers implement various security measures to protect email communication, including:

- **Encryption:** Using SSL/TLS to encrypt email data during transmission.
- **Authentication:** Requiring users to authenticate before sending or receiving emails.
- **Spam Filtering:** Using filters to detect and block spam emails.

By following these processes and protocols, a mail server ensures reliable and secure email communication.

## About the Project

In our project we are going to do just few following things because the complete mail server is very complex:

1. Recieve e-mail.
2. Send(redirect) email(SMTP Client)

When we receieve an email:

1. If the recepiient is in our domain `->` deliver the email to our local user.
2. Otherwise `->` send the email further.
