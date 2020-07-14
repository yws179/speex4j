#include <iostream>
#include "decoder.h"

using namespace std;

int main() {

    FILE * fin = fopen("/home/yws/Documents/speex4j/native/test/tianqi.spx", "r");
    FILE * fout = fopen("/home/yws/Documents/speex4j/native/test/out.pcm", "w");

    if (fin == NULL || fout == NULL) {
        cout << "文件无法打开" << endl;
        return 1;
    }

    fseek(fin, 0, SEEK_END);
    int len_data = ftell(fin);
    rewind(fin);
    char * data = (char*)malloc(sizeof(char) * len_data + 1);
    int rLen = fread(data, sizeof(char), len_data, fin);
    printf("rlen: %d", rLen);

    short output[100000];

    spx_init();

    int r = spx_decode(data, len_data, output, 42);
    printf("r: %d\n", r);
    fwrite(output, sizeof(short), r, fout);

    spx_destroy();

    fclose(fin);
    fclose(fout);

    return 0;
}
