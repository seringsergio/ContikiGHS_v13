#ifndef GHS_TEST_AR_H
#define GHS_TEST_AR_H

/*-------------------------------------------------------------------*/
/*---------------- INCLUDES -----------------------------------------*/
/*-------------------------------------------------------------------*/


#include "contiki.h"
#include "ghs_algorithm.h"
#include "net/rime/rime.h"
#include <stdio.h>

// NO BORRAR! //#include <inttypes.h> //para imprimir el INFINITO. NO BORRAR!
/*-------------------------------------------------------------------*/
/*---------------- Definiciones -------------------------------------*/
/*-------------------------------------------------------------------*/

#define INFINITO UINT32_MAX
#define MIN_CLOCK_SECOND 128
/*-------------------------------------------------------------------*/
/*---------------- TYPEDEF ------------------------------------------*/
/*-------------------------------------------------------------------*/
typedef struct fragment fragment;
typedef struct test_msg test_msg;
typedef struct test_list test_list;
typedef struct accept_msg accept_msg;
typedef struct reject_msg reject_msg;
typedef struct edges edges;
typedef struct report_msg report_msg;
typedef struct report_list report_list;
typedef struct name name;
typedef struct accept_list accept_list;
typedef struct reject_list reject_list;



/*-------------------------------------------------------------------*/
/*---------------- EVENTOS ------------------------------------------*/
/*-------------------------------------------------------------------*/
//estados
process_event_t e_evaluate_test;
process_event_t e_nd_lwoe; //Para saber si el nodo ya tiene su edge preferido
process_event_t e_ch_lwoe; // Para saber si los hijos ya reportaton el edge preferido


//msg
process_event_t e_msg_test;
process_event_t e_msg_reject;
process_event_t e_msg_accept;
process_event_t e_msg_ch_root;

/*-------------------------------------------------------------------*/
/*---------------- ESTRUCTURAS---------------------------------------*/
/*-------------------------------------------------------------------*/


/*-------------------------------------------------------------------*/
/*---------------- ESTRUCTURAS MSG-----------------------------------*/
/*-------------------------------------------------------------------*/


/*-------------------------------------------------------------------*/
/*---------------- Variables globales--------------------------------*/
/*-------------------------------------------------------------------*/


/*-------------------------------------------------------------------*/
/*----------------DECLARACION FUNCIONES -----------------------------*/
/*-------------------------------------------------------------------*/

void llenar_test_msg (test_msg *t_msg, const linkaddr_t *destination, fragment f);
void llenar_accept_msg (accept_msg *a_msg, const linkaddr_t *destination);
void llenar_reject_msg ( reject_msg *r_msg,  linkaddr_t *destination);
uint8_t become_accepted(edges *e_list_head_g, const linkaddr_t *from);
uint8_t become_rejected(edges *e_list_head_g, const linkaddr_t *from);
//uint32_t return_weight(edges *e_list_head_g,  const linkaddr_t *from);
uint8_t nombres_iguales(name *name_str_1, name *name_str_2);
void llenar_test_msg_list (test_list *t_list_out_p, const linkaddr_t *destination, fragment f);
void llenar_accept_msg_list (accept_list *a_list_out_p, const linkaddr_t *destination);
void llenar_reject_msg_list ( reject_list *rj_list_out_p,  linkaddr_t *destination);

#endif /* GHS_NEIGH_H */
