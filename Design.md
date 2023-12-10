# This document containing class description and design notes

-- An abstraction for sockets
TCPSocket

- fd

Backend : TCPSocket

- `Vector<Room>`

Room

- `Vector<User>` -- Users in room, appending while someone /login /exit
- `Vector<Message>` -- Message log

User

- std::string name | `std::vector<char>`
- int id

`Package<T>`

- T data
- size

Message : `Package<std::string>`

- User (sender)
