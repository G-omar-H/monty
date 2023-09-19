
# The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


## Authors

- [@KennyChukwuebuka](https://github.com/KennyChukwuebuka)
- [@OGhazi](https://github.com/G-omar-H)


## Deployment

To deploy this project run
```bash
 monty file
```
  where ```file``` is the path to the file containing Monty byte code.

The push opcode:

  The opcode push pushes an element to the stack.
```bash
push <int>
```
  where ```<int>``` is an integer.


The pall opcode:

The opcode pall prints all the values on the stack, starting from the top of the stack.
```bash
pall
```

