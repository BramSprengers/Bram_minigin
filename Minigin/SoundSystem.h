#pragma once

namespace dae
{
	//using sound_id = unsigned short;
	class SoundSystem
	{
		SoundSystem() = default;
		~SoundSystem() = default;
		SoundSystem(const SoundSystem& other) = delete;
		SoundSystem(SoundSystem&& other) = delete;
		SoundSystem& operator=(const SoundSystem& other) = delete;
		SoundSystem& operator=(SoundSystem&& other) = delete;

	public:

		static dae::SoundSystem& instance()
		{
			static dae::SoundSystem instance{};
			return instance;
		}

		void play();
	};
	/* {
		//using sound_id = unsigned short;
		//class SoundSystem
		//{
		//public:
		//	virtual ~SoundSystem() = default;
		//	virtual void play(const sound_id id, const float volume) = 0;
		//	// ...and other relevant methods of course...
		//};

		//class servicelocator final : public SoundSystem
		//{
		//	static std::unique_ptr<SoundSystem> _ss_instance;
		//public:
		//	virtual ~servicelocator() = default;
		//	static SoundSystem& get_sound_system() { return *_ss_instance; }
		//	servicelocator(std::unique_ptr<servicelocator>&& ss)
		//	{ _ss_instance = std::move(ss); }
		//	void play(const sound_id id, const float volume) override
		//	{
		//		volume;
		//		id;
		//		//SDL_AudioSpec* spec{};

		//		Mix_OpenAudioDevice(0, AUDIO_F32, 1, 0, nullptr, 0);

		//		auto* g_wave = Mix_LoadWAV("Date/Coin.wav");
		//		if(g_wave == nullptr)
		//		{
		//			throw("");
		//		}

		//		Mix_PlayChannel(-1, g_wave, 0);

		//		/*auto audioclip = audioclips[id];
		//		if (!audioclip->is_loaded())
		//			audioclip->load();
		//		audioclip->set_volume(volume);
		//		audioclip->play();
		//	}
		//};

		////class LoggingSoundSystem final : public SoundSystem {
		////	std::unique_ptr<SoundSystem> _real_ss;
		////public:
		////	LoggingSoundSystem(std::unique_ptr<servicelocator>&& ss) : _real_ss(std::move(ss)) {}
		////	virtual ~LoggingSoundSystem() = default;
		////	void play(const sound_id id, const float volume) override {
		////		_real_ss->play(id, volume);
		////		std::cout << "playing " << id << " at volume " << volume << std::endl;
		////	}
		////};
	}*/
}

