/*
 * File      : container.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2009, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-10-16     Bernard      first version
 */
#ifndef __RTGUI_CONTAINER_H__
#define __RTGUI_CONTAINER_H__

#include <rtgui/widgets/widget.h>

#ifdef __cplusplus
extern "C" {
#endif

DECLARE_CLASS_TYPE(container);
/** Gets the type of a container */
#define RTGUI_CONTAINER_TYPE       (RTGUI_TYPE(container))
/** Casts the object to an rtgui_container */
#define RTGUI_CONTAINER(obj)       (RTGUI_OBJECT_CAST((obj), RTGUI_CONTAINER_TYPE, rtgui_container_t))
/** Checks if the object is an rtgui_container */
#define RTGUI_IS_CONTAINER(obj)    (RTGUI_OBJECT_CHECK_TYPE((obj), RTGUI_CONTAINER_TYPE))

/*
 * the container widget
 */
struct rtgui_container
{
	struct rtgui_widget parent;

	struct rtgui_widget* focused;
	rtgui_list_t children;

	// TODO: remove this stuff that we don't need
	/* private field */
	char* title;
	rt_bool_t modal_show;
};
typedef struct rtgui_container rtgui_container_t;

rtgui_container_t* rtgui_container_create(const char* title);
void rtgui_container_destroy(rtgui_container_t* container);

rt_bool_t rtgui_container_event_handler(struct rtgui_object* widget, struct rtgui_event* event);

#ifndef RTGUI_USING_SMALL_SIZE
struct rtgui_box_t;
void rtgui_container_set_box(rtgui_container_t* container, rtgui_box_t* box);
#endif

rt_base_t rtgui_container_show(rtgui_container_t* container, rt_bool_t is_modal);
void rtgui_container_hide(rtgui_container_t* container);
void rtgui_container_end_modal(rtgui_container_t* container, rt_base_t modal_code);

char* rtgui_container_get_title(rtgui_container_t* container);
void rtgui_container_set_title(rtgui_container_t* container, const char* title);

void rtgui_container_add_child(rtgui_container_t *container, rtgui_widget_t* child);
void rtgui_container_remove_child(rtgui_container_t *container, rtgui_widget_t* child);
void rtgui_container_destroy_children(rtgui_container_t *container);
rtgui_widget_t* rtgui_container_get_first_child(rtgui_container_t* container);

rt_bool_t rtgui_container_event_handler(struct rtgui_object* widget, rtgui_event_t* event);

rt_bool_t rtgui_container_dispatch_event(rtgui_container_t *container, rtgui_event_t* event);
rt_bool_t rtgui_container_dispatch_mouse_event(rtgui_container_t *container, struct rtgui_event_mouse* event);

#ifdef __cplusplus
}
#endif

#endif
