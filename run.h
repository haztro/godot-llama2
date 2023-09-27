#ifdef __cplusplus
extern "C" {
#endif

void run_model(const char* checkpoint_path, float temperature, float topp, 
              int steps, const char* prompt, unsigned long long rng_seed, 
              const char* mode, const char* system_prompt, const char* tokenizer_path,
              char* output);

#ifdef __cplusplus
}
#endif
