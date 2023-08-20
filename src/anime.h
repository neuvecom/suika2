/* -*- coding: utf-8; tab-width: 8; indent-tabs-mode: t; -*- */

/*
 * Suika 2
 * Copyright (C) 2001-2021, TABATA Keiichi. All rights reserved.
 */

#ifndef SUIKA_ANIME_H
#define SUIKA_ANIME_H

#include "types.h"
#include "image.h"

/*
 * アニメーションレイヤーのインデックス
 */
enum anime_layer {
	ANIME_LAYER_BG,
	ANIME_LAYER_CHB,
	ANIME_LAYER_CHL,
	ANIME_LAYER_CHR,
	ANIME_LAYER_CHC,
	ANIME_LAYER_MSG,
	ANIME_LAYER_NAME,
	ANIME_LAYER_CHF,
	ANIME_LAYER_COUNT
};

/*
 * アニメーションの加速
 */
enum anime_accel {
	ANIME_ACCEL_UNIFORM,
	ANIME_ACCEL_ACCEL,
	ANIME_ACCEL_DEACCEL,
};

/* アニメーションサブシステムに関する初期化処理を行う */
bool init_anime(void);

/* アニメーションサブシステムに関する終了処理を行う */
void cleanup_anime(void);

/* アニメーションファイルを読み込む */
bool load_anime_from_file(const char *fname);

/* アニメーションシーケンスをクリアする */
void clear_anime_sequence(int layer);

/* アニメーションシーケンスを開始する */
bool new_anime_sequence(int layer);

/* アニメーションシーケンスにプロパティを追加する */
bool add_anime_sequence_property_f(const char *key, float val);
bool add_anime_sequence_property_i(const char *key, int val);

/* 指定したレイヤのアニメーションを開始する */
bool start_layer_anime(int layer);

/* 指定したレイヤのアニメーションを完了する */
bool finish_layer_anime(int layer);

/* 実行中のアニメーションがあるか調べる */
bool is_anime_running(void);

/* 実行中のアニメーションがあるか調べる */
bool is_anime_running_for_layer(int layer);

/* 完了したアニメーションがあるか調べる */
bool is_anime_finished_for_layer(int layer);

/* アニメーションのフレームを更新する */
void update_anime_frame(void);

/* レイヤのパラメータを取得する */
void
get_anime_layer_params(
	int layer,
	struct image **image,
	char **file,
	int *x,
	int *y,
	int *alpha);

#endif
