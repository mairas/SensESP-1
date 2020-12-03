#ifndef debounce_H
#define debounce_H

#include "transforms/transform.h"
#include <elapsedMillis.h>

/**
 * @brief DebounceTemplate is a passthrough transform that will output a value only when
 * there is ms_min_delay milliseconds between inputs.
 *
 * @tparam T The type of value being passed through Debounce.
 *
 * @param ms_min_delay The minimum amount of time that must have passed since
 * the previous input in order for the output to occur.
 *
 * @param config_path The path for configuring ms_min_delay with the Config UI.
 */
template<class T>
class DebounceTemplate : public SymmetricTransform<T> {
 public:
  DebounceTemplate(int ms_min_delay = 200, String config_path = "");

  virtual void set_input(T new_value, uint8_t input_channel = 0) override;

 private:
  elapsedMillis interrupt_timer_;
  int ms_min_delay_;
  virtual void get_configuration(JsonObject& doc) override;
  virtual bool set_configuration(const JsonObject& config) override;
  virtual String get_config_schema() override;
};

typedef DebounceTemplate<bool> DebounceBool;
typedef DebounceTemplate<bool> Debounce; // for backward-compatibility with original class
typedef DebounceTemplate<int> DebounceInt;
typedef DebounceTemplate<float> DebounceFloat;
typedef DebounceTemplate<String> DebounceString;

#endif