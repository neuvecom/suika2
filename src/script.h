﻿/* -*- coding: utf-8-with-signature; tab-width: 8; indent-tabs-mode: t; -*- */

/*
 * Suika 2
 * Copyright (C) 2001-2021, TABATA Keiichi. All rights reserved.
 */

/*
 * [Changes]
 *  - 2016/06/01 作成
 *  - 2017/08/14 スイッチに対応
 *  - 2018/07/21 @gosubに対応
 *  - 2019/09/17 @newsに対応
 *  - 2021/06/05 @menuのボタン数を増やした
 *  - 2021/06/10 @chにエフェクトとオフセットとアルファを追加
 *  - 2021/06/10 @chaに対応
 *  - 2021/06/12 @shakeに対応
 *  - 2021/06/15 @setsaveに対応
 *  - 2021/07/07 @goto $SAVEに対応
 *  - 2021/07/19 @chsに対応
 */

#ifndef SUIKA_SCRIPT_H
#define SUIKA_SCRIPT_H

#include "types.h"

/* コマンド構造体 */
struct command;

/* コマンドの種類 */
enum command_type {
	COMMAND_MIN,		/* invalid value */
	COMMAND_LABEL,
	COMMAND_SERIF,
	COMMAND_MESSAGE,
	COMMAND_BG,
	COMMAND_BGM,
	COMMAND_CH,
	COMMAND_CLICK,
	COMMAND_WAIT,
	COMMAND_GOTO,
	COMMAND_LOAD,
	COMMAND_VOL,
	COMMAND_SET,
	COMMAND_IF,
	COMMAND_SELECT,
	COMMAND_SE,
	COMMAND_MENU,
	COMMAND_RETROSPECT,
	COMMAND_SWITCH,
	COMMAND_GOSUB,
	COMMAND_RETURN,
	COMMAND_NEWS,
	COMMAND_CHA,
	COMMAND_SHAKE,
	COMMAND_SETSAVE,
	COMMAND_CHS,
	COMMAND_MAX		/* invalid value */
};

/* labelコマンドのパラメータ */
enum label_command_param {
	LABEL_PARAM_LABEL = 0,
};

/* セリフコマンドのパラメータ */
enum serif_command_param {
	SERIF_PARAM_PTR,
	SERIF_PARAM_NAME,
	SERIF_PARAM_VOICE,
	SERIF_PARAM_MESSAGE,
};

/* bgコマンドのパラメータ */
enum bg_command_param {
	BG_PARAM_FILE = 1,
	BG_PARAM_SPAN,
	BG_PARAM_METHOD,
};

/* bgmコマンドのパラメータ */
enum bgm_command_param {
	BGM_PARAM_FILE = 1,
};

/* chコマンドのパラメータ */
enum ch_command_param {
	CH_PARAM_POS = 1,
	CH_PARAM_FILE,
	CH_PARAM_SPAN,
	CH_PARAM_METHOD,
	CH_PARAM_OFFSET_X,
	CH_PARAM_OFFSET_Y,
	CH_PARAM_ALPHA,
};

/* waitコマンドのパラメータ */
enum wait_command_param {
	WAIT_PARAM_SPAN = 1,
};

/* gotoコマンドのパラメータ */
enum goto_command_param {
	GOTO_PARAM_LABEL = 1,
};

/* loadコマンドのパラメータ */
enum load_command_param {
	LOAD_PARAM_FILE = 1,
};

/* volコマンドのパラメータ */
enum vol_command_param {
	VOL_PARAM_STREAM = 1,
	VOL_PARAM_VOL,
	VOL_PARAM_SPAN,
};

/* setコマンドのパラメータ */
enum set_command_param {
	SET_PARAM_LHS = 1,
	SET_PARAM_OP,
	SET_PARAM_RHS,
};

/* ifコマンドのパラメータ */
enum if_command_param {
	IF_PARAM_LHS = 1,
	IF_PARAM_OP,
	IF_PARAM_RHS,
	IF_PARAM_LABEL,
};

/* selectコマンドのパラメータ */
enum select_command_param {
	SELECT_PARAM_LABEL1 = 1,
	SELECT_PARAM_LABEL2,
	SELECT_PARAM_LABEL3,
	SELECT_PARAM_TEXT1,
	SELECT_PARAM_TEXT2,
	SELECT_PARAM_TEXT3,
};

/* seコマンドのパラメータ */
enum se_command_param {
	SE_PARAM_FILE = 1,
	SE_PARAM_VOICE,
};

/* menuコマンドのパラメータ */
enum menu_command_param {
	MENU_PARAM_BG_FILE = 1,
	MENU_PARAM_FG_FILE,
	MENU_PARAM_LABEL1,
	MENU_PARAM_X1,
	MENU_PARAM_Y1,
	MENU_PARAM_W1,
	MENU_PARAM_H1,
	MENU_PARAM_LABEL2,
	MENU_PARAM_X2,
	MENU_PARAM_Y2,
	MENU_PARAM_W2,
	MENU_PARAM_H2,
	MENU_PARAM_LABEL3,
	MENU_PARAM_X3,
	MENU_PARAM_Y3,
	MENU_PARAM_W3,
	MENU_PARAM_H3,
	MENU_PARAM_LABEL4,
	MENU_PARAM_X4,
	MENU_PARAM_Y4,
	MENU_PARAM_W4,
	MENU_PARAM_H4,
	MENU_PARAM_LABEL5,
	MENU_PARAM_X5,
	MENU_PARAM_Y5,
	MENU_PARAM_W5,
	MENU_PARAM_H5,
	MENU_PARAM_LABEL6,
	MENU_PARAM_X6,
	MENU_PARAM_Y6,
	MENU_PARAM_W6,
	MENU_PARAM_H6,
	MENU_PARAM_LABEL7,
	MENU_PARAM_X7,
	MENU_PARAM_Y7,
	MENU_PARAM_W7,
	MENU_PARAM_H7,
	MENU_PARAM_LABEL8,
	MENU_PARAM_X8,
	MENU_PARAM_Y8,
	MENU_PARAM_W8,
	MENU_PARAM_H8,
	MENU_PARAM_LABEL9,
	MENU_PARAM_X9,
	MENU_PARAM_Y9,
	MENU_PARAM_W9,
	MENU_PARAM_H9,
	MENU_PARAM_LABEL10,
	MENU_PARAM_X10,
	MENU_PARAM_Y10,
	MENU_PARAM_W10,
	MENU_PARAM_H10,
	MENU_PARAM_LABEL11,
	MENU_PARAM_X11,
	MENU_PARAM_Y11,
	MENU_PARAM_W11,
	MENU_PARAM_H11,
	MENU_PARAM_LABEL12,
	MENU_PARAM_X12,
	MENU_PARAM_Y12,
	MENU_PARAM_W12,
	MENU_PARAM_H12,
	MENU_PARAM_LABEL13,
	MENU_PARAM_X13,
	MENU_PARAM_Y13,
	MENU_PARAM_W13,
	MENU_PARAM_H13,
	MENU_PARAM_LABEL14,
	MENU_PARAM_X14,
	MENU_PARAM_Y14,
	MENU_PARAM_W14,
	MENU_PARAM_H14,
	MENU_PARAM_LABEL15,
	MENU_PARAM_X15,
	MENU_PARAM_Y15,
	MENU_PARAM_W15,
	MENU_PARAM_H15,
	MENU_PARAM_LABEL16,
	MENU_PARAM_X16,
	MENU_PARAM_Y16,
	MENU_PARAM_W16,
	MENU_PARAM_H16,
};

/* retrospectコマンドのパラメータ */
enum retrospect_command_param {
	RETROSPECT_PARAM_BG_FILE = 1,
	RETROSPECT_PARAM_FG_FILE,
	RETROSPECT_PARAM_HIDE_R,
	RETROSPECT_PARAM_HIDE_G,
	RETROSPECT_PARAM_HIDE_B,
	RETROSPECT_PARAM_WIDTH,
	RETROSPECT_PARAM_HEIGHT,
	RETROSPECT_PARAM_LABEL1,
	RETROSPECT_PARAM_FLAG1,
	RETROSPECT_PARAM_X1,
	RETROSPECT_PARAM_Y1,
	RETROSPECT_PARAM_LABEL2,
	RETROSPECT_PARAM_FLAG2,
	RETROSPECT_PARAM_X2,
	RETROSPECT_PARAM_Y2,
	RETROSPECT_PARAM_LABEL3,
	RETROSPECT_PARAM_FLAG3,
	RETROSPECT_PARAM_X3,
	RETROSPECT_PARAM_Y3,
	RETROSPECT_PARAM_LABEL4,
	RETROSPECT_PARAM_FLAG4,
	RETROSPECT_PARAM_X4,
	RETROSPECT_PARAM_Y4,
	RETROSPECT_PARAM_LABEL5,
	RETROSPECT_PARAM_FLAG5,
	RETROSPECT_PARAM_X5,
	RETROSPECT_PARAM_Y5,
	RETROSPECT_PARAM_LABEL6,
	RETROSPECT_PARAM_FLAG6,
	RETROSPECT_PARAM_X6,
	RETROSPECT_PARAM_Y6,
	RETROSPECT_PARAM_LABEL7,
	RETROSPECT_PARAM_FLAG7,
	RETROSPECT_PARAM_X7,
	RETROSPECT_PARAM_Y7,
	RETROSPECT_PARAM_LABEL8,
	RETROSPECT_PARAM_FLAG8,
	RETROSPECT_PARAM_X8,
	RETROSPECT_PARAM_Y8,
	RETROSPECT_PARAM_LABEL9,
	RETROSPECT_PARAM_FLAG9,
	RETROSPECT_PARAM_X9,
	RETROSPECT_PARAM_Y9,
	RETROSPECT_PARAM_LABEL10,
	RETROSPECT_PARAM_FLAG10,
	RETROSPECT_PARAM_X10,
	RETROSPECT_PARAM_Y10,
	RETROSPECT_PARAM_LABEL11,
	RETROSPECT_PARAM_FLAG11,
	RETROSPECT_PARAM_X11,
	RETROSPECT_PARAM_Y11,
	RETROSPECT_PARAM_LABEL12,
	RETROSPECT_PARAM_FLAG12,
	RETROSPECT_PARAM_X12,
	RETROSPECT_PARAM_Y12,
};

/* switchコマンドのパラメータ */
enum switch_command_param {
	SWITCH_PARAM_PARENT_M1 = 1,
	SWITCH_PARAM_PARENT_M2,
	SWITCH_PARAM_PARENT_M3,
	SWITCH_PARAM_PARENT_M4,
	SWITCH_PARAM_PARENT_M5,
	SWITCH_PARAM_PARENT_M6,
	SWITCH_PARAM_PARENT_M7,
	SWITCH_PARAM_PARENT_M8,
	SWITCH_PARAM_CHILD1_L1,
	SWITCH_PARAM_CHILD1_M1,
	SWITCH_PARAM_CHILD1_L2,
	SWITCH_PARAM_CHILD1_M2,
	SWITCH_PARAM_CHILD1_L3,
	SWITCH_PARAM_CHILD1_M3,
	SWITCH_PARAM_CHILD1_L4,
	SWITCH_PARAM_CHILD1_M4,
	SWITCH_PARAM_CHILD1_L5,
	SWITCH_PARAM_CHILD1_M5,
	SWITCH_PARAM_CHILD1_L6,
	SWITCH_PARAM_CHILD1_M6,
	SWITCH_PARAM_CHILD1_L7,
	SWITCH_PARAM_CHILD1_M7,
	SWITCH_PARAM_CHILD1_L8,
	SWITCH_PARAM_CHILD1_M8,
	SWITCH_PARAM_CHILD2_L1,
	SWITCH_PARAM_CHILD2_M1,
	SWITCH_PARAM_CHILD2_L2,
	SWITCH_PARAM_CHILD2_M2,
	SWITCH_PARAM_CHILD2_L3,
	SWITCH_PARAM_CHILD2_M3,
	SWITCH_PARAM_CHILD2_L4,
	SWITCH_PARAM_CHILD2_M4,
	SWITCH_PARAM_CHILD2_L5,
	SWITCH_PARAM_CHILD2_M5,
	SWITCH_PARAM_CHILD2_L6,
	SWITCH_PARAM_CHILD2_M6,
	SWITCH_PARAM_CHILD2_L7,
	SWITCH_PARAM_CHILD2_M7,
	SWITCH_PARAM_CHILD2_L8,
	SWITCH_PARAM_CHILD2_M8,
	SWITCH_PARAM_CHILD3_L1,
	SWITCH_PARAM_CHILD3_M1,
	SWITCH_PARAM_CHILD3_L2,
	SWITCH_PARAM_CHILD3_M2,
	SWITCH_PARAM_CHILD3_L3,
	SWITCH_PARAM_CHILD3_M3,
	SWITCH_PARAM_CHILD3_L4,
	SWITCH_PARAM_CHILD3_M4,
	SWITCH_PARAM_CHILD3_L5,
	SWITCH_PARAM_CHILD3_M5,
	SWITCH_PARAM_CHILD3_L6,
	SWITCH_PARAM_CHILD3_M6,
	SWITCH_PARAM_CHILD3_L7,
	SWITCH_PARAM_CHILD3_M7,
	SWITCH_PARAM_CHILD3_L8,
	SWITCH_PARAM_CHILD3_M8,
	SWITCH_PARAM_CHILD4_L1,
	SWITCH_PARAM_CHILD4_M1,
	SWITCH_PARAM_CHILD4_L2,
	SWITCH_PARAM_CHILD4_M2,
	SWITCH_PARAM_CHILD4_L3,
	SWITCH_PARAM_CHILD4_M3,
	SWITCH_PARAM_CHILD4_L4,
	SWITCH_PARAM_CHILD4_M4,
	SWITCH_PARAM_CHILD4_L5,
	SWITCH_PARAM_CHILD4_M5,
	SWITCH_PARAM_CHILD4_L6,
	SWITCH_PARAM_CHILD4_M6,
	SWITCH_PARAM_CHILD4_L7,
	SWITCH_PARAM_CHILD4_M7,
	SWITCH_PARAM_CHILD4_L8,
	SWITCH_PARAM_CHILD4_M8,
	SWITCH_PARAM_CHILD5_L1,
	SWITCH_PARAM_CHILD5_M1,
	SWITCH_PARAM_CHILD5_L2,
	SWITCH_PARAM_CHILD5_M2,
	SWITCH_PARAM_CHILD5_L3,
	SWITCH_PARAM_CHILD5_M3,
	SWITCH_PARAM_CHILD5_L4,
	SWITCH_PARAM_CHILD5_M4,
	SWITCH_PARAM_CHILD5_L5,
	SWITCH_PARAM_CHILD5_M5,
	SWITCH_PARAM_CHILD5_L6,
	SWITCH_PARAM_CHILD5_M6,
	SWITCH_PARAM_CHILD5_L7,
	SWITCH_PARAM_CHILD5_M7,
	SWITCH_PARAM_CHILD5_L8,
	SWITCH_PARAM_CHILD5_M8,
	SWITCH_PARAM_CHILD6_L1,
	SWITCH_PARAM_CHILD6_M1,
	SWITCH_PARAM_CHILD6_L2,
	SWITCH_PARAM_CHILD6_M2,
	SWITCH_PARAM_CHILD6_L3,
	SWITCH_PARAM_CHILD6_M3,
	SWITCH_PARAM_CHILD6_L4,
	SWITCH_PARAM_CHILD6_M4,
	SWITCH_PARAM_CHILD6_L5,
	SWITCH_PARAM_CHILD6_M5,
	SWITCH_PARAM_CHILD6_L6,
	SWITCH_PARAM_CHILD6_M6,
	SWITCH_PARAM_CHILD6_L7,
	SWITCH_PARAM_CHILD6_M7,
	SWITCH_PARAM_CHILD6_L8,
	SWITCH_PARAM_CHILD6_M8,
	SWITCH_PARAM_CHILD7_L1,
	SWITCH_PARAM_CHILD7_M1,
	SWITCH_PARAM_CHILD7_L2,
	SWITCH_PARAM_CHILD7_M2,
	SWITCH_PARAM_CHILD7_L3,
	SWITCH_PARAM_CHILD7_M3,
	SWITCH_PARAM_CHILD7_L4,
	SWITCH_PARAM_CHILD7_M4,
	SWITCH_PARAM_CHILD7_L5,
	SWITCH_PARAM_CHILD7_M5,
	SWITCH_PARAM_CHILD7_L6,
	SWITCH_PARAM_CHILD7_M6,
	SWITCH_PARAM_CHILD7_L7,
	SWITCH_PARAM_CHILD7_M7,
	SWITCH_PARAM_CHILD7_L8,
	SWITCH_PARAM_CHILD7_M8,
	SWITCH_PARAM_CHILD8_L1,
	SWITCH_PARAM_CHILD8_M1,
	SWITCH_PARAM_CHILD8_L2,
	SWITCH_PARAM_CHILD8_M2,
	SWITCH_PARAM_CHILD8_L3,
	SWITCH_PARAM_CHILD8_M3,
	SWITCH_PARAM_CHILD8_L4,
	SWITCH_PARAM_CHILD8_M4,
	SWITCH_PARAM_CHILD8_L5,
	SWITCH_PARAM_CHILD8_M5,
	SWITCH_PARAM_CHILD8_L6,
	SWITCH_PARAM_CHILD8_M6,
	SWITCH_PARAM_CHILD8_L7,
	SWITCH_PARAM_CHILD8_M7,
	SWITCH_PARAM_CHILD8_L8,
	SWITCH_PARAM_CHILD8_M8,
};

/* gosubコマンドのパラメータ */
enum gosub_command_param {
	GOSUB_PARAM_LABEL = 1,
};

/* chaコマンドのパラメータ */
enum cha_command_param {
	CHA_PARAM_POS = 1,
	CHA_PARAM_SPAN,
	CHA_PARAM_ACCEL,
	CHA_PARAM_OFFSET_X,
	CHA_PARAM_OFFSET_Y,
	CHA_PARAM_ALPHA,
};

/* shakeコマンドのパラメータ */
enum shake_command_param {
	SHAKE_PARAM_MOVE = 1,
	SHAKE_PARAM_SPAN,
	SHAKE_PARAM_TIMES,
	SHAKE_PARAM_AMOUNT,
};

/* setsaveコマンドのパラメータ */
enum setsave_command_param {
	SETSAVE_PARAM_MODE = 1,
};

/* chsコマンドのパラメータ */
enum chs_command_param {
	CHS_PARAM_CENTER = 1,
	CHS_PARAM_RIGHT,
	CHS_PARAM_LEFT,
	CHS_PARAM_BACK,
	CHS_PARAM_SPAN,
	CHS_PARAM_BG,
	CHS_PARAM_METHOD,
};

/*
 * 初期化
 */

/* 初期スクリプトを読み込む */
bool init_script(void);

/* コマンドを破棄する */
void cleanup_script(void);

/*
 * スクリプトとコマンドへの公開アクセス
 */

/* スクリプトをロードする */
bool load_script(const char *fname);

/* スクリプトファイル名を取得する */
const char *get_script_file_name(void);

/* 実行中のコマンドのインデックスを取得する(セーブ用) */
int get_command_index(void);

/* 実行中のコマンドのインデックスを設定する(gosub,ロード用) */
bool move_to_command_index(int index);

/* 次のコマンドに移動する */
bool move_to_next_command(void);

/* ラベルへ移動する */
bool move_to_label(const char *label);

/* gosubによるリターンポイントを記録する(gosub用) */
void push_return_point(void);

/* gosubによるリターンポイントを取得する(return用) */
int pop_return_point(void);

/* gosubによるリターンポイントの行番号を設定する(ロード用) */
bool set_return_point(int index);

/* gosubによるリターンポイントの行番号を取得する(セーブ用) */
int get_return_point(void);

/* 最後のコマンドであるかを取得する(@goto $SAVE用) */
bool is_final_command(void);

/* コマンドの行番号を取得する(ログ用) */
int get_line_num(void);

/* コマンドの行全体を取得する(ログ用) */
const char *get_line_string(void);

/* コマンドのタイプを取得する */
int get_command_type(void);

/* 文字列のコマンドパラメータを取得する */
const char *get_string_param(int index);

/* 整数のコマンドパラメータを取得する */
int get_int_param(int index);

/* 浮動小数点数のコマンドパラメータを取得する */
float get_float_param(int index);

#endif
