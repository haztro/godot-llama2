/* llama2.h */

#ifndef LLAMA2_H
#define LLAMA2_H

#include "core/object/ref_counted.h"

class Llama2 : public RefCounted {
    GDCLASS(Llama2, RefCounted);

protected:
    static void _bind_methods();

public:
    String run(const String &checkpoint_path, float temperature, float topp, 
                int steps, const String &prompt, unsigned long long rng_seed,
                const String &mode, const String &system_prompt, const String &tokenizer_path);

    Llama2();
};

#endif // LLAMA2_H