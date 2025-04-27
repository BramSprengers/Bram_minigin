#include "SoundSystem.h"

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.c"

#include <memory>
#include <iostream>
#include <vector>
#include <SDL.h>
#include <stdio.h>

void dae::SoundSystem::play()
{
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format = ma_format_f32;   // Set to ma_format_unknown to use the device's native format.
    config.playback.channels = 2;               // Set to 0 to use the device's native channel count.
    config.sampleRate = 48000;           // Set to 0 to use the device's native sample rate.
    //config.dataCallback = data_callback;   // This function will be called when miniaudio needs more data.
    //config.pUserData = pMyCustomData;

    ma_result result;

    ma_device device;
    ma_engine engine;
    ma_sound sound;

    std::string link{ "Coion.wav" };

    result = ma_engine_init(nullptr, &engine);

    if (result != MA_SUCCESS) std::cout << "engine faild to init\n";

    if (ma_device_init(NULL, &config, &device) != MA_SUCCESS)std::cout << "faild to init device\n";

    ma_device_start(&device);

    result = ma_sound_init_from_file(&engine, link.c_str(),0 ,nullptr , nullptr, &sound);

    if (result != MA_SUCCESS) std::cout << "Could not load file: " << result << " \n";

    ma_sound_start(&sound);

    ma_engine_uninit(&engine);
    ma_device_uninit(&device);
    ma_sound_uninit(&sound);
}
