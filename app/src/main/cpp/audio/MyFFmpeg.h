//
// Created by jiuxs on 20-8-4.
//

#ifndef NDKDEMO_MYFFMPEG_H
#define NDKDEMO_MYFFMPEG_H

#include <pthread.h>
#include <malloc.h>
#include "MyJNICall.h"
#include "MyAudio.h"
#include "../android_log.h"
#include "../video/MyVideo.h"

extern "C" {
#include "libavformat/avformat.h"
#include "libswresample/swresample.h"
};

class MyFFmpeg {
public:
    AVFormatContext *avFormatContext = nullptr;
    char *url = nullptr;
    MyPlayerStatus *myPlayerStatus = nullptr;
    MyJNICall *myJNICall = nullptr;
    MyAudio *myAudio = nullptr;
    MyVideo *myVideo = nullptr;

public:
    MyFFmpeg(MyJNICall *myJNICall, char *url);
    ~MyFFmpeg();

public:
    void play();
    void prepare();
    void prepareAsync();
    void prepare(ThreadMode threadMode);
    void setSurface(JNIEnv *env, jobject surface);

private:
    void release();
    void callPlayerJNIError(ThreadMode threadMode, int code, const char *msg);
};


#endif //NDKDEMO_MYFFMPEG_H
