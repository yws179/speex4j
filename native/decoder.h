//
// Created by yws on 2020/7/9.
//

#ifndef SPEEX4J_DECODER_H
#define SPEEX4J_DECODER_H

#include <speex/speex.h>
#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif

void spx_init();

int get_frame_size();

int spx_decode(char *i_data, int i_len, short *o_data, int nbBytes);

void spx_destroy();


#ifdef __cplusplus
}
#endif
#endif //SPEEX4J_DECODER_H
