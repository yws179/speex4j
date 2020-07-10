//
// Created by yws on 2020/7/7.
//

#include "com_github_yws179_speex_SpeexDecoder.h"
#include "decoder.h"
#include <stdlib.h>

JNIEXPORT void JNICALL Java_com_github_yws179_speex_SpeexDecoder_init(JNIEnv * env, jclass jclass)
{
    spx_init();
}

JNIEXPORT jshortArray JNICALL Java_com_github_yws179_speex_SpeexDecoder_decode(JNIEnv * env, jclass jclass, jbyteArray jbyteArray, jint nbBytes)
{
    int len_data = (*env)->GetArrayLength(env, jbyteArray);
    jboolean isCopy = 0;
    jbyte * data = (*env)->GetByteArrayElements(env, jbyteArray, &isCopy);

    short * output = (short *) malloc(sizeof(short) * len_data / nbBytes * get_frame_size());

    int len = spx_decode(data, len_data, output, nbBytes);

    (*env)->ReleaseByteArrayElements(env, jbyteArray, data, 0);

    jshortArray jshortArr = (*env)->NewShortArray(env, len);
    (*env)->SetShortArrayRegion(env, jshortArr, 0, len, output);

    free(output);
    return jshortArr;
}

JNIEXPORT void JNICALL Java_com_github_yws179_speex_SpeexDecoder_destroy(JNIEnv * env, jclass jclass)
{
    spx_destroy();
}

