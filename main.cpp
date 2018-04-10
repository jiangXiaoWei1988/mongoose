#include <QCoreApplication>
#include "mongoose.h"
#include <QDebug>
//static int s_exit_flag = 0;
//static int s_show_headers = 0;
//static const char *s_show_headers_opt = "--show-headers";
static struct mg_serve_http_opts s_http_server_opts;
static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
//  struct http_message *hm = (struct http_message *) ev_data;

//  switch (ev) {
//    case MG_EV_CONNECT:
//      if (*(int *) ev_data != 0) {
//        fprintf(stderr, "connect() failed: %s\n", strerror(*(int *) ev_data));
//        s_exit_flag = 1;
//      }
//      break;
//    case MG_EV_HTTP_REPLY:
//      nc->flags |= MG_F_CLOSE_IMMEDIATELY;
//      if (s_show_headers) {
//        fwrite(hm->message.p, 1, hm->message.len, stdout);
//      } else {
//        fwrite(hm->body.p, 1, hm->body.len, stdout);
//      }
//      putchar('\n');
//      s_exit_flag = 1;
//      break;
//    case MG_EV_CLOSE:
//      if (s_exit_flag == 0) {
//        printf("Server closed connection\n");
//        s_exit_flag = 1;
//      }
//      break;
//    default:
//      break;
//  }
    if (ev != MG_EV_HTTP_REQUEST)
    {
//        qDebug()<<"ev != MG_EV_HTTP_REQUEST";
//        qDebug("%d",ev);
        return ;
    }
    qDebug()<<"\nStart.";

//    struct http_message *hm = (struct http_message *) ev_data;
    mg_serve_http(nc, (struct http_message *) ev_data, s_http_server_opts);


    return;
}
static char* s_http_port = "60003";
int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
//    return a.exec();

//    struct mg_mgr mgr;
//    int i;

//    mg_mgr_init(&mgr, NULL);

//    /* Process command line arguments */
//    for (i = 1; i < argc; i++) {
//      if (strcmp(argv[i], s_show_headers_opt) == 0) {
//        s_show_headers = 1;
//      } else if (strcmp(argv[i], "--hexdump") == 0 && i + 1 < argc) {
//        mgr.hexdump_file = argv[++i];
//      } else {
//        break;
//      }
//    }

//    if (i + 1 != argc) {
//      fprintf(stderr, "Usage: %s [%s] [--hexdump <file>] <URL>\n", argv[0],
//              s_show_headers_opt);
//      exit(EXIT_FAILURE);
//    }

//    mg_connect_http(&mgr, ev_handler, argv[i], NULL, NULL);

//    while (s_exit_flag == 0) {
//      mg_mgr_poll(&mgr, 1000);
//    }
//    mg_mgr_free(&mgr);
//    return 0;
    struct mg_mgr mgr;
    struct mg_connection *nc;
    mg_mgr_init(&mgr, NULL);
    nc = mg_bind(&mgr,s_http_port , ev_handler);
    mg_set_protocol_http_websocket(nc);
    mg_enable_multithreading(nc);
    if(nc == NULL)
    {
        qDebug("nc == NULL");
        return false;
    }
    while (true) {
        mg_mgr_poll(&mgr, 1000);

    }
    mg_mgr_free(&mgr);
    return 0;
}
