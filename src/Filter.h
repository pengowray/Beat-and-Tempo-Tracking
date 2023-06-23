#ifndef __FILTER__

#ifdef __cplusplus 
extern "C"{
#endif  //__cplusplus 

#include "DLL.h"

typedef struct opaque_filter_struct Filter;

typedef enum filter_type_enum
{
  FILTER_LOW_PASS,
  FILTER_HIGH_PASS,
  FILTER_BAND_PASS,
  FILTER_BAND_STOP,
  FILTER_NUMBER_OF_TYPES,
}filter_type_t;

typedef enum filter_window_enum
{
  FILTER_WINDOW_RESERVED = 0,
  FILTER_WINDOW_RECT,
  FILTER_WINDOW_BARTLETT,
  FILTER_WINDOW_HANN,
  FILTER_WINDOW_HAMMING,
  FILTER_WINDOW_BLACKMANN,
}filter_window_t;

Filter*         filter_new            (filter_type_t type, float cutoff, int order);
Filter*         filter_destroy        (Filter* self);

DLL_EXPORT  void            filter_clear          (Filter* self);
DLL_EXPORT  void            filter_set_filter_type(Filter* self, filter_type_t type);
DLL_EXPORT  filter_type_t   filter_get_filter_type(Filter* self);
DLL_EXPORT  void            filter_set_sample_rate(Filter* self, float sample_rate);
DLL_EXPORT  float           filter_get_sample_rate(Filter* self);
DLL_EXPORT  void            filter_set_cutoff     (Filter* self, float cutoff);
DLL_EXPORT  float           filter_get_cutoff     (Filter* self);
DLL_EXPORT  void            filter_set_order      (Filter* self, int order); //cannot be greater than the initial order...
DLL_EXPORT  int             filter_get_order      (Filter* self);
DLL_EXPORT  void            filter_set_window_type(Filter* self, filter_window_t window);
DLL_EXPORT  filter_window_t filter_get_window_type(Filter* self);
  
DLL_EXPORT  void            filter_process_data   (Filter* self, float* data, int num_samples);

#ifdef __cplusplus 
}
#endif
#endif //__FILTER__
