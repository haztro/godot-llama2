# godot-llama2

Hacky module to get kaparthy's [llama2.c](https://github.com/karpathy/llama2.c) running locally in Godot.

## Installation

Clone the repo then copy it into the modules folder (as llama2) of the Godot Engine source and compile:

```bash
cp -R godot-llama2 godot/modules/llama2
```

## Usage

```gdscript
var llama2 = Llama2.new()
var result: String = llama2.run("path/to/model", 1.0, 0.9, 256, "Once upon a time", 0, "generate", "", "path/to/tokenizer")
```

where you can provide a model and tokenizer binary (just add in the res:// folder). I suggest calling run() from a separate thread - see inside demo/ for a minimal example where I use stories110.bin and tokenizer.bin provided in [llama2.c](https://github.com/karpathy/llama2.c). Only the "generate" mode works currently ("chat" mode is unimplemented).

It's pretty slow so not really practical but kinda neat.
