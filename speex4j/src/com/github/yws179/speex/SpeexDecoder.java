package com.github.yws179.speex;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/**
 * @author yws
 * @date 2020/07/07
 */
public class SpeexDecoder {

    static {
        System.loadLibrary("speex4j");
    }

    public static native void init();

    public static native short[] decode(byte[] data, int nbBytes);

    public static native void destroy();

    public static byte[] shortArr2byteArr(short[] shortArr, int shortArrLen){
        byte[] byteArr = new byte[shortArrLen * 2];
        ByteBuffer.wrap(byteArr).order(ByteOrder.LITTLE_ENDIAN).asShortBuffer().put(shortArr);
        return byteArr;
    }

}
