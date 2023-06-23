/*-____--_--------_---_-----_---_------------_--------------------------#include "DLL.h"

  / ___|| |_ __ _| |_(_)___| |_(_) ___ ___  | |__  
  \___ \| __/ _` | __| / __| __| |/ __/ __| | '_ \ 
   ___) | || (_| | |_| \__ \ |_| | (__\__ \_| | | |
  |____/ \__\__,_|\__|_|___/\__|_|\___|___(_)_| |_|
------------------------------------------------------------------------

----------------------------------------------------------------------*/
#ifndef __IC_STATISTICS__
#define __IC_STATISTICS__

#include "DLL.h"

#if defined(__cplusplus)
extern "C"{
#endif   //(__cplusplus)

/*--------------------------------------------------------------------*/
/*--___-------_-_--------------_----------------------------------------
   / _ \ _ _ | (_)_ _  ___    /_\__ _____ _ _ __ _ __ _ ___ 
  | (_) | ' \| | | ' \/ -_)  / _ \ V / -_) '_/ _` / _` / -_);
   \___/|_||_|_|_|_||_\___| /_/ \_\_/\___|_| \__,_\__, \___|
--------------------------------------------------|___/-----------------
  Calculate the mean and variance of a signal one sample at a time.
----------------------------------------------------------------------*/
            typedef struct     opaque_online_average_struct     OnlineAverage;
DLL_EXPORT  OnlineAverage*     online_average_new               ();
DLL_EXPORT  void               online_average_init              (OnlineAverage* self);
DLL_EXPORT  OnlineAverage*     online_average_destroy           (OnlineAverage* self);
DLL_EXPORT  int                online_average_n                 (OnlineAverage* self);
DLL_EXPORT  double             online_average_mean              (OnlineAverage* self);
DLL_EXPORT  double             online_average_variance          (OnlineAverage* self);
DLL_EXPORT  double             online_average_std_dev           (OnlineAverage* self);
DLL_EXPORT  void               online_average_update            (OnlineAverage* self, double     x);

/*--------------------------------------------------------------------*/
/*-__--__---------_---------------_-------------------------------------
  |  \/  |_____ _(_)_ _  __ _    /_\__ _____ _ _ __ _ __ _ ___ 
  | |\/| / _ \ V / | ' \/ _` |  / _ \ V / -_) '_/ _` / _` / -_);
  |_|  |_\___/\_/|_|_||_\__, | /_/ \_\_/\___|_| \__,_\__, \___|
------------------------|___/------------------------|___/--------------
  Calculate the moving or rolling mean and variance over the past N
  samples of a signal. This algorithm is online and updates one sample
  at a time.
----------------------------------------------------------------------*/
            typedef struct     opaque_moving_average_struct     MovingAverage;
DLL_EXPORT  MovingAverage*     moving_average_new               (unsigned N);
DLL_EXPORT  void               moving_average_init              (MovingAverage* self);
DLL_EXPORT  MovingAverage*     moving_average_destroy           (MovingAverage* self);
DLL_EXPORT  int                moving_average_N                 (MovingAverage* self);
DLL_EXPORT  int                moving_average_n                 (MovingAverage* self);
DLL_EXPORT  double             moving_average_mean              (MovingAverage* self);
DLL_EXPORT  double             moving_average_variance          (MovingAverage* self);
DLL_EXPORT  double             moving_average_std_dev           (MovingAverage* self);
DLL_EXPORT  void               moving_average_update            (MovingAverage* self, double     x);

/*--------------------------------------------------------------------*/
/*--___-------_-_------------___------------------------_---------------
   / _ \ _ _ | (_)_ _  ___  | _ \___ __ _ _ _ ___ _____(_)___ _ _  
  | (_) | ' \| | | ' \/ -_) |   / -_) _` | '_/ -_|_-<_-< / _ \ ' \ 
   \___/|_||_|_|_|_||_\___| |_|_\___\__, |_| \___/__/__/_\___/_||_|
------------------------------------|___/-------------------------------
  Calculate the means, variances, covariance, slope, y-intercept and 
  correlation coeficient of two signals. This is an online algorithm
  that operates one sample at a time.
----------------------------------------------------------------------*/
            typedef struct     opaque_online_regression_struct  OnlineRegression;
DLL_EXPORT  OnlineRegression*  online_regression_new            ();
DLL_EXPORT  void               online_regression_init           (OnlineRegression* self);
DLL_EXPORT  OnlineRegression*  online_regression_destroy        (OnlineRegression* self);
DLL_EXPORT  int                online_regression_n              (OnlineRegression* self);
DLL_EXPORT  double             online_regression_covariance     (OnlineRegression* self);
DLL_EXPORT  double             online_regression_slope          (OnlineRegression* self);
DLL_EXPORT  double             online_regression_y_intercept    (OnlineRegression* self);
DLL_EXPORT  double             online_regression_r_squared      (OnlineRegression* self);
DLL_EXPORT  void               online_regression_update         (OnlineRegression* self, double     a_data, double     b_data);

/*--------------------------------------------------------------------*/
/*----------_-----------_---_-----------_____-_---------------_----_----    _    _ 
    /_\  __| |__ _ _ __| |_(_)_ _____  |_   _| |_  _ _ ___ __| |_ | |_  ___| |__| |
   / _ \/ _` / _` | '_ \  _| \ V / -_)   | | | ' \| '_/ -_|_-< ' \| ' \/ _ \ / _` |
  /_/ \_\__,_\__,_| .__/\__|_|\_/\___|   |_| |_||_|_| \___/__/_||_|_||_\___/_\__,_|
------------------|_|---------------------------------------------------
  Adaptive threshhold tells you when your signal goes a specified number
  of standard deviations above or below a moving average of a filtered
  version of your signal. update() returns +1 or -1 whenever your signal
  transitions to being above or below the threshold.
----------------------------------------------------------------------*/
            typedef struct     opaque_adaptive_threshold_struct AdaptiveThreshold;
DLL_EXPORT  AdaptiveThreshold* adaptive_threshold_new              (unsigned N);
DLL_EXPORT  void               adaptive_threshold_init             (AdaptiveThreshold* self);
DLL_EXPORT  void               adaptive_threshold_clear            (AdaptiveThreshold* self);
DLL_EXPORT  AdaptiveThreshold* adaptive_threshold_destroy          (AdaptiveThreshold* self);
DLL_EXPORT  double             adaptive_threshold_smoothing        (AdaptiveThreshold* self);
DLL_EXPORT  void               adaptive_threshold_set_smoothing    (AdaptiveThreshold* self, double     coefficient);
DLL_EXPORT  double             adaptive_threshold_threshold_value  (AdaptiveThreshold* self); //mean + num std devs * std dev
DLL_EXPORT  double             adaptive_threshold_threshold        (AdaptiveThreshold* self); //num std devs
DLL_EXPORT  void               adaptive_threshold_set_threshold    (AdaptiveThreshold* self, double     std_devs);
DLL_EXPORT  double             adaptive_threshold_threshold_min    (AdaptiveThreshold* self);
DLL_EXPORT  void               adaptive_threshold_set_threshold_min(AdaptiveThreshold* self, double min); //raw value
DLL_EXPORT  double             adaptive_threshold_onset_signal     (AdaptiveThreshold* self);
DLL_EXPORT  double             adaptive_threshold_mean             (AdaptiveThreshold* self);
DLL_EXPORT  double             adaptive_threshold_update           (AdaptiveThreshold* self, double     x);
DLL_EXPORT  
DLL_EXPORT  double             statistics_random_flat(); //(0, 1]
DLL_EXPORT  double             statistics_random_normal(double     mean, double     std_dev);
DLL_EXPORT  double             statistics_random_cauchy(double peak_location, double half_width_at_half_maximum);

#if defined(__cplusplus)
}
#endif   //(__cplusplus)

#endif   //__IC_STATISTICS__

