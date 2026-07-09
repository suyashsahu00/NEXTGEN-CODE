1) What are 3 things your computer (client) might request from a server?
index.html
style.css
scripts.js
JSON file

2) What is the main job of a server?
to reply to the request. clients ask, the server provides.


3) Self study: what would the 3-digit server response code 
be if the server experiences an internal server error?
HTTP response status codes indicate whether a specific HTTP request has been successfully completed. Responses are grouped in five classes:

Informational responses (100 – 199)
Successful responses (200 – 299)
Redirection messages (300 – 399)
Client error responses (400 – 499)
Server error responses (500 – 599)

✅ Successful responses
200 OK – Standard success for most requests (GET, POST, etc.)

201 Created – A new resource was successfully created (common with POST)

204 No Content – Request succeeded but no content is returned (often for DELETE)

🔀 Redirection messages
301 Moved Permanently – Resource permanently moved to a new URL

302 Found – Resource temporarily moved

304 Not Modified – Used for caching; resource hasn’t changed

⚠️ Client error responses
400 Bad Request – Malformed request or invalid syntax

401 Unauthorized – Authentication required

403 Forbidden – Client is authenticated but not allowed access

404 Not Found – Resource doesn’t exist or URL invalid (the most famous one)

429 Too Many Requests – Rate limiting; client sent too many requests

💥 Server error responses
500 Internal Server Error – Generic server-side failure

502 Bad Gateway – Invalid response from upstream server

503 Service Unavailable – Server overloaded or down for maintenance

504 Gateway Timeout – Upstream server didn’t respond in time