# 📜 Get Next Line

Welcome to **Get Next Line**, my first complex project as a student at the renowned 42 School! 🚀 This project challenged me to implement a function capable of reading and returning a single line from a file descriptor, handling edge cases, and working efficiently with a static variable—all while adhering to strict coding standards.

## 📖 Table of Contents

- 🌟 [Overview](#overview)
- ⚙️ [How It Works](#how-it-works)
- ✨ [Features](#features)
- 💻 [Usage](#usage)
  - [Manual Compilation](#manual-compilation)
  - [Example](#example)
- 📦 [Installation](#installation)
- 🛤️ [My Journey](#my-journey)
- 🚀 [Bonus](#bonus)
- 📝 [License](#license)
- 🎉 [Thank You!](#thank-you)

## 🌟 Overview

The goal of this project is to create a function called `get_next_line` that reads and returns one line at a time from a file or standard input. It's a crucial step in learning how to manage memory, work with file descriptors, and build efficient algorithms in C.

Here's what `get_next_line` does:
- Reads text line by line from a file descriptor.
- Handles edge cases like large files, small buffers, and no newline at the end.
- Utilizes a static variable to preserve state between function calls.
- Efficiently frees memory to avoid leaks.

This project is a rite of passage for any 42 student, and I am proud to share my solution!

## ⚙️ How It Works

`get_next_line` is built with the following key concepts:

### Static Variable:
The static variable stores leftover data from the previous function call, ensuring continuity across multiple calls.

### Dynamic Buffer:
Reads from the file descriptor in chunks of size `BUFFER_SIZE`, which can vary during testing.

### Helper Functions:
- `ft_read`: Reads and appends data to the saved buffer until a newline or EOF is reached.
- `ft_split_line`: Extracts the next full line from the buffer.
- `ft_trim_line`: Removes the processed line from the buffer for the next call.

### Memory Management:
Memory allocation and deallocation are handled meticulously to avoid leaks.

## ✨ Features
- Reads from any valid file descriptor.
- Handles both files and standard input.
- Returns `NULL` at EOF or on error.
- Efficient with memory and avoids leaks.
- **Bonus**: Supports multiple file descriptors simultaneously!

## 💻 Usage

### Manual Compilation

To compile the project manually, use the following commands:

1. **Mandatory Version**:  
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 src/get_next_line.c src/get_next_line_utils.c src/main.c -I include
```

2. **Bonus Version**:  
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 src/get_next_line_bonus.c src/get_next_line_utils_bonus.c src/main.c -I include
```

Once compiled, the program can be run with the following command:

```bash
./a.out
```

### Example

Here’s an example of how to use the `get_next_line` function:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("src/test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Expected Output

For a file like `test.txt` with content:

```
Hello, world!
This is my first line-reading program.
Enjoy!
```

The expected output will be:

```
Hello, world!
This is my first line-reading program.
Enjoy!
```

## 📦 Installation

Clone the repository:

```bash
git clone https://github.com/your-username/get_next_line.git
cd get_next_line
```

Once inside the project directory, use the manual compilation steps to compile the project and create the executable.

## 🛤️ My Journey

Get Next Line is not just a project—it's a testament to my growth as a programmer. Starting with minimal C knowledge, I tackled:
- Understanding file descriptors.
- Using static variables to persist data across function calls.
- Managing dynamic memory allocation and avoiding leaks.

This project taught me resilience, debugging skills, and the importance of reading documentation thoroughly. It represents my first milestone at 42, and I'm excited to share it with the world. 🌍

## 🚀 Bonus

The bonus part adds the following functionality:

### Multiple File Descriptors:
`get_next_line` can handle multiple files simultaneously without mixing their contents. This means you can switch between files seamlessly, maintaining the state of each file descriptor.

### Dynamic `BUFFER_SIZE`:
The function adapts to varying `BUFFER_SIZE` values, ensuring robustness for different scenarios.

## 📝 License

This project is licensed under the MIT License. Feel free to use, modify, and share it!

## 🎉 Thank You!

If you’ve made it this far, thank you for taking the time to explore my project! I’m proud of what I’ve built and can’t wait to tackle even more challenging projects at 42. If you have any feedback or questions, feel free to reach out or open an issue.
