// AppCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <jni.h>
#include<iostream>



using namespace std;

JNIEnv* create_vm(JavaVM ** jvm) {

	JNIEnv *env;
	JavaVMInitArgs vm_args;

	JavaVMOption options;
	//Path to the java source code     
	options.optionString = (char*) "-Djava.class.path=D:\\Java Src\\TestStruct";
	vm_args.version = JNI_VERSION_1_6; //JDK version. This indicates version 1.6
	vm_args.nOptions = 1;
	vm_args.options = &options;
	vm_args.ignoreUnrecognized = 0;

	int ret = JNI_CreateJavaVM(jvm, (void**)&env, &vm_args);
	if (ret < 0)
		printf("\nUnable to Launch JVM\n");

	cout << "JVM load succeeded: Version ";
	jint ver = env->GetVersion();
	cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

	return env;
}

void init_JVM() 
{

	JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
	JNIEnv *env;                      // Pointer to native interface
									  //================== prepare loading of Java VM ============================
	JavaVMInitArgs vm_args;                        // Initialization arguments
	JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
	options[0].optionString = (char*) "-Djava.class.path=.";   // where to find java .class
	vm_args.version = JNI_VERSION_1_8;             // minimum Java version
	vm_args.nOptions = 1;                          // number of options
	vm_args.options = options;
	vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
											//=============== load and initialize Java VM and JNI interface =============
	jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
	delete options;    // we then no longer need the initialisation options. 
	if (rc != JNI_OK) {
		// TO DO: error processing... 
		cin.get();
		exit(EXIT_FAILURE);
	}
	//=============== Display JVM version =======================================
	cout << "JVM load succeeded: Version ";
	jint ver = env->GetVersion();
	cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

	// TO DO: add the code that will use JVM <============  (see next steps)

	jvm->DestroyJavaVM();
	cin.get();

#if 0
	jclass cls = env->FindClass("Factorial");
	if (cls != nullptr) 
	{
		jmethodID computeMehod = env->GetStaticMethodID(cls, "computeFactStatic4", "()V");
		
		if (computeMehod != nullptr) {

			env->CallStaticVoidMethod(cls, computeMehod);
			long res = 1;
			cout << res << endl;
		}
		else
			cout << " not found !" << endl;
	}
	else
		cout << "class not found !" << endl;

#endif

}

int main()
{
	cout << "hi from CPP app" << endl;
	init_JVM();
    return 0;
}

