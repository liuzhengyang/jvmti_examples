//
// Created by liuzhengyang on 2020/4/25.
//
#include <iostream>
#include "jvmti.h"


jint printLoadedClasses(JavaVM *vm);

JNIEXPORT jint JNICALL
Agent_OnLoad(JavaVM *vm, char *options, void *reserved) {
    std::cout << "Agent OnLoad" << std::endl;
    return 0;
}

jint JNICALL
Agent_OnAttach(JavaVM *vm, char *options, void *reserved) {
    std::cout << "Agent OnAttach" << std::endl;
    return printLoadedClasses(vm);
}

JNIEXPORT void JNICALL
Agent_OnUnload(JavaVM *vm) {
    std::cout << "Agent OnUnload" << std::endl;
}

JNIEXPORT jint printLoadedClasses(JavaVM *vm) {
    jvmtiEnv *jvmti;

    jint result = vm->GetEnv((void **) &jvmti, JVMTI_VERSION_1_2);
    if (result != JNI_OK) {
        std::cout << "Unable to access jvm env" << std::endl;
        return result;
    }

    jclass *classes;
    jint count;
    result = jvmti->GetLoadedClasses(&count, &classes);
    if (result != JNI_OK) {
        std::cout << "JVMTI GetLoadedClasses failed" << std::endl;
        return result;
    }

    for (int i = 0; i < count; i++) {
        char *sig;
        char *genericSig;
        jvmti->GetClassSignature(classes[i], &sig, &genericSig);
        std::cout << "class signature = " << sig << std::endl;
    }

    return 0;
}
