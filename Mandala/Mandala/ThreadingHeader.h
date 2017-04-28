#pragma once
#include <chrono>
#include <thread>
#include <atomic>

//region SpeechRecognition

#include <ppltasks.h>
#include <agents.h>
#include <concrt.h>
#include <concrtrm.h>
#include <concurrent_priority_queue.h>
#include <concurrent_queue.h>
#include <concurrent_unordered_map.h>
#include <concurrent_unordered_set.h>
#include <concurrent_vector.h>
#include <internal_concurrent_hash.h>
#include <internal_split_ordered_list.h>
#include <ppl.h>
#include <pplcancellation_token.h>
#include <pplinterface.h>

//endregion

// pplconcrt.h no linked
#include <ShlDisp.h>