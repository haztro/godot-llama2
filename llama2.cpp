#include "llama2.h"
#include "run.h"


// Run the model with the given a prompt
String Llama2::run(const String &checkpoint_path, float temperature, float topp, 
              int steps, const String &prompt, unsigned long long rng_seed, 
              const String &mode, const String &system_prompt, const String &tokenizer_path) {

    // Convert to C strings
    CharString checkpoint_path_cs = checkpoint_path.utf8();
    CharString prompt_cs = prompt.utf8();
    CharString mode_cs = mode.utf8();
    CharString system_prompt_cs = system_prompt.utf8();
    CharString tokenizer_path_cs = tokenizer_path.utf8();

    const char* checkpoint_path_c = checkpoint_path_cs.get_data();
    const char* prompt_c = prompt_cs.get_data();
    const char* mode_c = mode_cs.get_data();
    const char* system_prompt_c = system_prompt_cs.get_data();
    const char* tokenizer_path_c = tokenizer_path_cs.get_data();

    char* output = (char*)malloc(1000*sizeof(char));

    // Run the model
    run_model(checkpoint_path_c, temperature, topp, steps, prompt_c, rng_seed, mode_c, system_prompt_c, tokenizer_path_c, output);

    return output;
}


void Llama2::_bind_methods() {
    ClassDB::bind_method(D_METHOD("run", "checkpoint_path", "temperature", "topp", "steps", "prompt", "rng_seed", "mode", "system_prompt", "tokenizer_path"), &Llama2::run);
}

Llama2::Llama2() {
    
}