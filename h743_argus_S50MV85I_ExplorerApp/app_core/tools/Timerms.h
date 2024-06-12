/*
 * Timerms.h
 *
 *  Created on: May 21, 2024
 *      Author: admin
 */

#ifndef KLS_TIMERMS_H_
#define KLS_TIMERMS_H_

#include <cstdint>
#include <functional>

class Timer_ms
{
public:
	Timer_ms() = default;
	Timer_ms(std::function<void(const uint32_t current_time, const uint32_t dt)> event): m_event(event) {}
	virtual ~Timer_ms();

	inline void set_event_and_ms(const uint32_t dt_ms, const std::function<void(const uint32_t current_time, const uint32_t dt)> event) { m_dt_ms = dt_ms; m_event = event; }
	inline void set_event(const std::function<void(const uint32_t current_time, const uint32_t dt)> event) { m_event = event; }
	inline void set_time_ms(const uint32_t dt_ms) { m_dt_ms = dt_ms; }

	void proceed(const uint32_t current_time);

private:
	uint32_t m_dt_ms;
	uint32_t m_last_time;
	std::function<void(const uint32_t current_time, const uint32_t dt)> m_event = nullptr;
};

#endif /* KLS_TIMERMS_H_ */
