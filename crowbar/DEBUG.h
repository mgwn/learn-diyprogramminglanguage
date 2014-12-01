#ifndef PUBLIC_DBG_H_INCLUDED
#define PUBLIC_DBG_H_INCLUDED
#include <stdio.h>
#include <stdarg.h>

typedef struct DBG_Controller_tag *DBG_Controller;
void DBG_set(DBG_Controller controller,char *file, int line);
void DBG_set_expression(char *expresssion);

#ifdef DBG_NO_DEBUG
#define DBG_create_controller()         ((void)0)
#define DBG_set_debug_level(level)      ((void)0)
#define DBG_set_debug_write_fp(fp)      ((void)0)
#define DBG_asser(expression,arg)       ((void)0)
#define DBG_panic(arg)                  ((void)0)
#define DBG_debug_write(arg)            ((void)0)
#else /* DBG_NO_DEBUG */
#ifdef DBG_CONTROLLER
#define DBG_CURRENT_CONTROLLER DBG_CONTROLLER
#else /* DBG_CONTROLLER */
#define DBG_CURRENT_CONTROLLER dbg_default_controller
#endif /* DBG_CONTROLLER */
extern DBG_Controller DBG_CURRENT_CONTROLLER;

#define DBG_create_controller() (DBG_create_controller_func())
#define DBG_set_debug_level(level) \
(DBG_set_debug_level_func(DBG_CURRENT_CONTROLLER,(level)))
#define DBG_set_debug_write_fp(fp) \
(DBG_set_debug_write_fp_func(DBG_CURRENT_CONTROLLER,(fp)))
//由于宏中不能使用连续可变长参数，所以只能通过直接定义，在使用时加括号的方式
#define DBG_asser(expression,arg) \
 ((expression) ? (void)(0) :\
  ((DBG_set(DBG_CURRENT_CONTROLLER, __FILE__, __LINE__)),\
    (DBG_set_expression(#expression)),\
    DBG_asset_func arg))
#define DBG_panic(arg) \
(DBG_set(DBG_CURRENT_CONTROLLER,__FILE__,__LINE__)),\
 DBG_panic_func arg)
#define DBG_debug_write(arg) \
 ((DBG_set(DBG_CURRENT_CONTROLLER, __FILE__, __LINE__)),\
  DBG_debug_write_func arg)
#endif /* DBG_NO_DEBUG */


typedef enum {
    DBG_TRUE = 1,
    DBG_FALSE = 0
} DBG_Boolean;

DBG_Controller DBG_create_controller_func(void);
void DBG_set_debug_level_func(DBG_Controller controller, int level);
void DBG_set_debug_write_fp_func(DBG_Controller controller, FILE *fp);
void DBG_asset_func(char *fmt, ...);
void DBG_panic_func(char *fmt, ...);
void DBG_debug_write_func(int level,char *fmt, ...);
#endif /* PUBLIC_DBG_H_INCLUDED */