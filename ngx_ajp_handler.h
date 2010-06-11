
#ifndef _NGX_AJP_HANDLER_H_INCLUDED_
#define _NGX_AJP_HANDLER_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
#include <ngx_ajp_module.h>
#include <ajp.h>


typedef enum {
    ngx_http_ajp_st_init_state = 0,
    ngx_http_ajp_st_forward_request_sent,
    ngx_http_ajp_st_request_body_data_sending,
    ngx_http_ajp_st_request_send_all_done,
    ngx_http_ajp_st_response_recv_headers,
    ngx_http_ajp_st_response_parse_headers_done,
    ngx_http_ajp_st_response_headers_sent,
    ngx_http_ajp_st_response_body_data_sending,
    ngx_http_ajp_st_response_end
} ngx_http_ajp_state_e;

typedef struct {
    ngx_http_ajp_state_e           state;
    size_t                         length;
    ajp_msg_t                      msg;

    ngx_chain_t                   *save;
    ngx_chain_t                   *body;

    ngx_uint_t                     ajp_reuse; /* unsigned :1 */

} ngx_http_ajp_ctx_t;

ngx_int_t ngx_http_ajp_handler(ngx_http_request_t *r);

#endif /* _NGX_AJP_HANDLER_H_INCLUDED_ */
