#pragma once

#include <jni.h>

#include <string>

#define EXCEPTION_CHECK(env) \
	if ((env)->ExceptionCheck()) \
	{ \
		(env)->ExceptionDescribe(); \
		(env)->ExceptionClear(); \
		return; \
	}

class CJavaWrapper
{

    jmethodID s_GetClipboardText;
    jmethodID s_CallLauncherActivity;

    jmethodID s_showspawn;
    jmethodID s_hidespawn;

    jmethodID s_RadarBR;

    jmethodID s_ShowInputLayout;
    jmethodID s_HideInputLayout;

    jmethodID s_ShowClientSettings;
    jmethodID s_SetUseFullScreen;
    jmethodID s_MakeDialog;

    jmethodID s_showHud;
    jmethodID s_hideHud;
    jmethodID s_updateHudInfo;

    jmethodID s_showradar;
    jmethodID s_hideradar;

    jmethodID s_showGps;
    jmethodID s_hideGps;

    jmethodID s_showZona;
    jmethodID s_hideZona;

    jmethodID s_showx2;
    jmethodID s_hidex2;

    jmethodID s_showSpeed;
    jmethodID s_hideSpeed;
    jmethodID s_updateSpeedInfo;

    jmethodID s_showNotification;
    jmethodID s_AddChatMessage;//

    jmethodID s_setPauseState;

    jmethodID s_showSplash;
    jmethodID s_updateSplash;
public:
    JNIEnv* GetEnv();

    std::string GetClipboardString();
    void CallLauncherActivity(int type);

    void ShowInputLayout();
    void HideInputLayout();

    void ShowRadar();
    void HideRadar();

    void SetRadar();
    void AddChatMessage(const char msg[], int color);

    void ShowClientSettings();

    void SetUseFullScreen(int b);

    void UpdateHudInfo(int health, int armour, int hunger, int weaponidweik, int ammo, int ammoinclip, int money, int wanted);
    void ShowHud();
    void HideHud();

    void ShowGPS();
    void HideGPS();

    void ShowZona();
    void HideZona();

    void ShowX2();
    void HideX2();

    void UpdateSpeedInfo(int speed, int fuel, int hp, int mileage, int engine, int light, int belt, int lock);
    void ShowSpeed();
    void HideSpeed();

    void MakeDialog(int dialogId, int dialogTypeId, char* caption, char* content, char* leftBtnText, char* rightBtnText); // Диалоги
    void ShowNotification(int type, char* text, int duration, char* actionforBtn, char* textBtn);

    void SetPauseState(bool a1);
    void setTurnState();

    void ShowSplash();
    void UpdateSplash(int progress, int i);

    CJavaWrapper(JNIEnv* env, jobject activity);
    ~CJavaWrapper();

    void ShowSpawn();
    void HideSpawn();

    jobject activity;
    jmethodID s_connectedgar;
};

extern CJavaWrapper* g_pJavaWrapper;