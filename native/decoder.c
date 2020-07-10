//
// Created by yws on 2020/7/9.
//
#include "decoder.h"
#include <stdio.h>

static SpeexBits bits;
static void * dec_state;
static int frame_size;
static int is_init = 0;


void spx_init()
{
    speex_bits_init(&bits);
    dec_state = speex_decoder_init(&speex_nb_mode);
    int enh = 1;
    speex_decoder_ctl(dec_state, SPEEX_SET_ENH, &enh);
    speex_decoder_ctl(dec_state, SPEEX_GET_FRAME_SIZE, &frame_size);
    is_init = 1;
}

int get_frame_size()
{
    return frame_size;
}

int spx_decode(char * i_data, int i_len, short * o_data, int nbBytes)
{
    if (!is_init)
    {
        spx_init();
    }

    short output_buffer[1024];
    int decoded_length = 0;
    int i = 0;

    for (i = 0; decoded_length < i_len; ++i)
    {
        speex_bits_reset(&bits);
        speex_bits_read_from(&bits, i_data + decoded_length, nbBytes);
        speex_decode_int(dec_state, &bits, output_buffer);
        decoded_length += nbBytes;
        memcpy(o_data + frame_size * i, output_buffer, frame_size * sizeof(short));
    }

    return frame_size * i;
}

void spx_destroy()
{
    if (is_init)
    {
        is_init = 0;
        speex_decoder_destroy(dec_state);
        speex_bits_destroy(&bits);
    }
}
