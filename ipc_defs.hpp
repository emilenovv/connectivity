///
 /// ipc_defs.hpp
 ///
 ///  Created on: Jul 14, 2015
 ///      Author: visteon
///

#ifndef IPC_DEFS_HPP_
#define IPC_DEFS_HPP_

#include <semaphore.h>
#include <string.h>

typedef short cid_t;

typedef union operand1_t
{
    int op1_i;
    char op1_ch[17];
}operand1_t;

typedef union operand2_t
{
    int op2_i;
    char op2_ch[17];
}operand2_t;

typedef union result_t
{
    int result_int;
    char result_char[33];
    }result_t;

typedef enum operation_t
{
    ADD = 1, SUBSTRACT,
    MULTIPLY, DIVIDE,
    CONCAT, SUBSTR
}operation_t;



typedef struct shared
{
    operand1_t operand1;
    operand2_t operand2;
    operation_t operation;
    result_t result;
    cid_t client_id;
    pthread_mutex_t mtx;

    pthread_cond_t server_ready;
    pthread_cond_t answer_calculated[2];
    pthread_cond_t client_done[2];

    sem_t sem1;

    bool client_flag[2], answer_done[2];
    bool server_flag, new_request; //*_flag = true when the * is has completed its job with the shared memory
}shared;

typedef struct courier
{
    operand1_t operand1;
    operand2_t operand2;
    operation_t operation;
    result_t result;
    cid_t client_id;
}courier;

typedef struct channel
{
    courier* src;
    shared* dst;
}channel;

typedef void (*cb_t)(shared* sh);

typedef struct callback_t
{
    shared* shmem;
    cb_t cb;
    cid_t cid;
}callback_t;

#endif /* IPC_DEFS_HPP_ */
