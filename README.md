# MyShell

<p align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/a/af/Tux.png" width="120" alt="Linux"/>

<br><br>

![C](https://img.shields.io/badge/C-Programming-00599C?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-GNU%2FLinux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![POSIX](https://img.shields.io/badge/POSIX-API-007ACC?style=for-the-badge)
![System Calls](https://img.shields.io/badge/System-Calls-8A2BE2?style=for-the-badge)
![System Programming](https://img.shields.io/badge/System-Programming-FF6F00?style=for-the-badge)
![GNU Readline](https://img.shields.io/badge/GNU-Readline-228B22?style=for-the-badge&logo=gnu&logoColor=white)
![MIT License](https://img.shields.io/badge/License-MIT-success?style=for-the-badge)

</p>
## About

**MyShell** is an educational Linux mini shell written in **C**.

The goal of this project is to learn **Linux system calls**, **POSIX APIs**, and **C system programming** by building a simple shell from scratch.

The shell currently supports several basic Unix commands implemented for learning purposes.

Whenever possible, this project uses **low-level Linux system calls** instead of higher-level library functions to better understand how Unix shells work internally.

This project is still under development, and more features will be added over time to make the shell closer to a real Unix shell.

---

## Features

### Commands

- `ls`
- `ls -l`
- `cat`
- `touch`
- `mkdir`

### Redirection

- `>`
- `>>`
- `<`
- `2>`

---

## Build and run 

```bash
make
```

---
```bash
./myshell
```

---

## Example

```bash
myshell> ls

myshell> ls -l

myshell> touch file.txt

myshell> mkdir project

myshell> cat file.txt

myshell> ls > output.txt

myshell> cat < output.txt
```

---

## Future Work

- Pipes (`|`)
- Background execution (`&`)
- Signal handling (`Ctrl+C`, `Ctrl+Z`)
- Environment variables
- Wildcards (`*`)
- Command history
- Auto-completion
- Built-in commands (`pwd`, `export`, `unset`, `env`)
- Improved parser
- HTML/CSS project documentation

---

## License

This project is released under the **MIT License** and is intended for educational purposes.# myshell-linux-mini-shell

