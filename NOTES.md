**3/18/26**

**truncate**: if you do "wb" when opening a file, it **truncates** that file, or **cuts** the contents of the file to **0 bytes** -> wiping it basically. `So truncate might mean cutting down on size`.

**eod**: refactor and fix `read()` function

**3/19/26** 

so I'm currently having trouble where my `read()` function isn't properly reading the binary data. But the thing is it was and I realized that in my `read()` function, I had a `strncmp` operation that added `\0` to the end of a string, which was converted into binary. So it would only read and end up until that `\0` 😭.

**eod**: Trouble with writing and reading to .bin file. fix required

**3/21/26**

refactored `read()` function in `options.c`. A LOT of clutter removed and reading properly works now, decided to read byte by byte to skip over null-termination, and then null-terminate at the end.

Also I added the same features for "GOALS", so it should probably work now smoothly

**eod**: "SETTINGS" needs some functionality; Deletion for tasks; Updating (re-edit) tasks
