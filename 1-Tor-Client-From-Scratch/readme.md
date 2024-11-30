# Concepts Needed for the TOR Client Implementation

## SOCKS4 Protocol

### What is the SOCKS4 Protocol?

SOCKS4 is a proxy protocol designed to relay traffic between a client and a server through an intermediate server (proxy). It operates at the transport layer (Layer 4) and primarily supports **TCP connections**. Its main purpose is to facilitate communication when direct connections are restricted or undesirable.

---

### Layman Explanation

Imagine you're in a library that blocks access to certain websites. You can’t directly access the blocked website, so you ask a friend (the proxy) outside the library to fetch the information for you.

1. **You tell your friend** which website you want to visit.
2. **Your friend fetches the website's content** and brings it back to you.
3. **You don’t talk directly** to the website; everything goes through your friend.

SOCKS4 acts like your "friend" in this scenario, allowing you to communicate indirectly with the server you want to reach.

---

### How Does SOCKS4 Work?

#### 1. **Client-Proxy Connection**

- The client (you) initiates a **TCP connection** to the SOCKS4 proxy server.
- This connection is established on a specific port (commonly **1080** for SOCKS proxies).

---

#### 2. **Request from Client to Proxy**

Once the connection is established, the client sends a request to the proxy. The request includes the following components:

- **Command Code (1 byte):**
  - `0x01` = Establish a TCP connection (CONNECT command).
  - `0x02` = Bind a port (rarely used, for accepting incoming connections).
- **Port Number (2 bytes):** The destination server’s port (e.g., `80` for HTTP).

- **IP Address (4 bytes):** The destination server’s IPv4 address.

- **User ID (variable-length):** A null-terminated string representing the user’s ID (optional for authentication).

---

#### 3. **Proxy-Server Connection**

- The proxy server processes the client’s request.
- It attempts to establish a TCP connection with the specified destination server.

---

#### 4. **Response from Proxy to Client**

The proxy server sends a response back to the client, which contains:

- **Version (1 byte):** Always `0x00` in SOCKS4.
- **Reply Code (1 byte):** Indicates the result of the connection attempt:

  - `90` = Request granted.
  - `91` = Request rejected or failed.
  - `92` = Request rejected because the proxy cannot connect to the client.
  - `93` = Request rejected because the proxy cannot resolve the destination address.

- **Port Number (2 bytes):** Echoed back from the request (ignored in practice).
- **IP Address (4 bytes):** Echoed back from the request (ignored in practice).

---

#### 5. **Data Exchange**

- If the proxy grants the request (`0x5A`), it acts as a bridge between the client and the destination server.
- **Client-to-proxy-to-server communication:**
  - Data sent by the client is relayed to the destination server through the proxy.
  - Data sent by the server is relayed back to the client through the proxy.

---

### Technicalities and Limitations

1. **IPv4 Only:** SOCKS4 supports only IPv4 addresses. For IPv6, SOCKS5 or other protocols are required.

2. **No Encryption:** SOCKS4 does not encrypt data. It merely forwards it, leaving sensitive information exposed to potential interception.

3. **No Authentication:** SOCKS4 has minimal support for authentication (only user ID), making it less secure compared to SOCKS5.

4. **Limited Commands:** SOCKS4 supports only TCP connections. SOCKS5 adds support for UDP.

5. **DNS Resolution:** The client handles DNS resolution (translating domain names to IP addresses). This means the client must resolve the server's IP address before making a request.

**NOTE**: Refer [SOCKS4PROTOCOL](https://www.openssh.com/txt/socks4.protocol) for more detailed summary.
