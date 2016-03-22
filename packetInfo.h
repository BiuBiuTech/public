#ifndef __SERVER_LOGIN_PACKET_HEADER__
#define __SERVER_LOGIN_PACKET_HEADER__

#include "def.h"
#include "dbdef.h"
#include "packet.h"

#include "../BaseSupport/string.h"
#include "../BaseSupport/array.h"
#include "../BaseSupport/bitset.h"

namespace tech{

class C2SVersionInfo
{
public:
	template<typename T>
	void map(T& s)
	{
		s << version;
		s << flag;
	}
	static const int ID = PACKET_C2S_VERSION_INFO;
	int version;
	char flag;
};

class S2CServerInfo
{
public:
	template<typename T>
	void map(T& s)
	{
		s << ret;
		s << ip;
		s << port;
	}

	static const int ID = PACKET_S2C_SERVER_INFO;
	unsigned char ret; // ret==0 success. ret != 0 版本号不同;
	string32	ip;
	short		port;
};

class ErrorPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << packetid;
		s << errorCode;
	}

	static const int ID = PACKET_ERROR;

	int packetid;
	int errorCode;
};

class SuccessPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << packetid;
		s << code;
	}

	static const int ID = PACKET_SUCCESS;
	int packetid;
	int code;
};

class PingPacket
{
public:
	template <typename T>
	void map(T& s)
	{
		s << nothing;
	}

	static const int ID = PACKET_PING;
	int nothing;
};

class LoginPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << userID;
		s << openkey;
		s << headIcon;
		s << gender;
		s << nickName;
		s << isSdk;
		s << version;
	}

	static const int ID = PACKET_LOGIN;

	STRING_OPEN_ID	userID;			// openid;
	STRING_OPEN_KEY	openkey;		// openkey;
	STRING_HEAD_URL	headIcon;
	int				gender;
	STRING_NICKNAME	nickName;
	char			isSdk;			//
	int				version;
};

class LoginPacketResult
{
public:
	template<typename T>
	void map(T& s)
	{
		s << result;
		s << userID;
	}

	static const int ID = PACKET_LOGINRESULT;

	unsigned short	result;
	int				userID;
};

class ChangeInfoPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << nickname;
		s << head;
	}

	static const int ID = PACKET_CHANGE_INFO;

	STRING_NICKNAME		nickname;	// 修改昵称
	int					head;		// 修改头像
};

class ChangeIconPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << head;
	}

	static const int ID = PACKET_C2S_CHANGE_ICON;
	STRING_HEAD_URL head;
};

class ChangeInfoPacketResult
{
public:
	template<typename T>
	void map(T& s)
	{
		s << result;
	}

	static const int ID = PACKET_CHANGE_INFO_RET;

	int		result;
};

class PacketSyncPlayer
{
public:

	const int&	getAttr	(const int index) const	{ return m_attr[index];	}
	bool	isSetAttr(const int index) { return __optional_flag__attr[index]; }
	void	setAttr	(const int index, const int& value)	{ m_attr[index] = value; __optional_flag__attr.set(index);	}

	static const int ID = PACKET_SYNC_PLAYER_ATTR;

	template <typename StreamerT>
	void map(StreamerT& s)
	{
		s << __optional_flag__attr;
		for (int i = 0; i < m_attr.capacity(); ++i)
		{
			if (__optional_flag__attr[i])
				s << m_attr[i];
		}
	}

private:
	mw_base::array<int, PLAYER_ATTR_COUNT>	m_attr;			//属性数组
	mw_base::Bitset<PLAYER_ATTR_COUNT>	__optional_flag__attr;
};

class PacketSyncAttr64
{
public:
	const long long&	getAttr64	(const int index) const	{ return m_timeAttr[index];	}
	bool	isSetAttr64(const int index) { return __optional_flag__timeAttr[index]; }
	void	setAttr64	(const int index, const long long& value)	{ m_timeAttr[index] = value; __optional_flag__timeAttr.set(index);	}

	template <typename StreamerT>
	void map(StreamerT& s)
	{		
		s << __optional_flag__timeAttr;
		for (int i = 0; i < m_timeAttr.capacity(); ++i)
		{
			if (__optional_flag__timeAttr[i])
				s << m_timeAttr[i];
		}		
	}

	static const int ID = PACKET_SYNC_PLAYER_ATTR64;

private:
	mw_base::array<long long, PLAYER_ATTR64_COUNT>	m_timeAttr;			//时间属性数组
	mw_base::Bitset<PLAYER_ATTR64_COUNT>	__optional_flag__timeAttr;
};


class PacketSyncStrings
{
public:
	const string128&	getAttrString	(const int index) const	{ return m_attrString[index];	}
	bool	isSetAttrString(const int index) { return __optional_flag__attrString[index]; }
	void	setAttrString	(const int index, const string128& value)	{ m_attrString[index] = value; __optional_flag__attrString.set(index);	}

	template <typename StreamerT>
	void map(StreamerT& s)
	{
		s << __optional_flag__attrString;
		for (int i = 0; i < m_attrString.capacity(); ++i)
		{
			if (__optional_flag__attrString[i])
				s << m_attrString[i];
		}
	}

	static const int ID = PACKET_SYNC_PLAYER_STRINGS;

private:
	mw_base::array<string128, PLAYER_ATTR_STRING_COUNT>	m_attrString;			//字符串属性数组
	mw_base::Bitset<PLAYER_ATTR_STRING_COUNT>	__optional_flag__attrString;
};

class PacketSyncMoney
{
public:

	const long long&	getMoney	(const int index) const	{ return m_money[index];	}
	bool	isSetMoney(const int index) { return __optional_flag__money[index]; }
	void	setMoney	(const int index, const long long& value)	{ m_money[index] = value; __optional_flag__money.set(index);	}


	static const int ID = PACKET_SYNC_MONEY;

	template <typename StreamerT>
	void map(StreamerT& s)
	{
		s << __optional_flag__money;
		for (int i = 0; i < m_money.capacity(); ++i)
		{
			if (__optional_flag__money[i])
				s << m_money[i];
		}
	}

private:
	mw_base::array<long long, MONEY_TYPE_COUNT>	m_money;			//货币数组
	mw_base::Bitset<MONEY_TYPE_COUNT>	__optional_flag__money;
};

class PacketSyncTime
{
public:
	const long long&	getTime	(const int index) const	{ return m_time[index];	}
	bool	isSetTime(const int index) { return __optional_flag__time[index]; }
	void	setTime	(const int index, const long long& value)	{ m_time[index] = value; __optional_flag__time.set(index);	}


	static const int ID = PACKET_SYNC_PLAYER_TIME;

	template <typename StreamerT>
	void map(StreamerT& s)
	{
		s << __optional_flag__time;
		for (int i = 0; i < m_time.capacity(); ++i)
		{
			if (__optional_flag__time[i])
				s << m_time[i];
		}
	}

private:
	mw_base::array<long long, PLAYER_ATTR_TIME_COUNT>	m_time;			//货币数组
	mw_base::Bitset<PLAYER_ATTR_TIME_COUNT>	__optional_flag__time;
};

class PacketSyncExtra
{
public:
	static const int ID = PACKET_SYNC_EXTRA;

	int getExtra(const int index) const { return m_extra[index]; }
	bool isExtra(const int index) {return __optional_flag_extra[index];}
	void setExtra(const int index, const int v) {m_extra[index] = v; __optional_flag_extra.set(index);}

	template<typename T>
	void map(T& s)
	{
		s << __optional_flag_extra;
		for (int i = 0; i < PLAYER_EXTRA_ATTR_COUNT; ++i)
		{
			if (__optional_flag_extra[i])
				s << m_extra[i];
		}
	}
private:
	mw_base::array<int, PLAYER_EXTRA_ATTR_COUNT> m_extra;
	mw_base::Bitset<PLAYER_EXTRA_ATTR_COUNT> __optional_flag_extra;
};


class PacketSaveAttrs
{
public:
// 	enum SUBJECT_DATA
// 	{
// 		ATTR_INT_SUNJECT,	//科目
// 		ATTR_INT_VERSION,	//版本
// 		ATTR_INT_GRADE,		//年级
// 		ATTR_INT_CHAPTER,	//章节
// 		ATTR_INT_CLASS_HOURS,//课时
// 	};

	char subject;
	char version;
	char grade;
	char chapter;
	char classIndex;

	enum ATTR_INT
	{
		ATTR_INT_INVALID=-1,

		ATTR_INT_GOLD,		//金币
		ATTR_INT_EXP,		//经验

		ATTR_INT_ZOOM,		// 放大镜.
		ATTR_INT_DOOM,		// 炸弹.
		ATTR_INT_OVERTIME,	// 延迟时间.
		ATTR_INT_INFO,		// 提示类型.
		
		ATTR_INT_COUNT,
	};
	enum ATTR_INT64
	{
		ATTR_INT64_INVALID=-1,
		ATTR_INT64_COUNT,
	};

	const int&	getAttr	(const int index) const	{ return m_attrs[index];	}
	bool	isSetAttr(const int index) { return __optional_flag_int__[index]; }
	void	setAttr	(const int index, const int& value)	{ m_attrs[index] = value; __optional_flag_int__.set(index);	}

	static const int ID = PACKET_SAVE_ATTRS;

	template <typename StreamerT>
	void map(StreamerT& s)
	{
		s << subject;
		s << version;
		s << grade;
		s << chapter;
		s << classIndex;

		s << __optional_flag_int__;
		for (int i = 0; i < m_attrs.capacity(); ++i)
		{
			if (__optional_flag_int__[i])
				s << m_attrs[i];
		}
	}

private:
	mw_base::array<int, ATTR_INT_COUNT>	m_attrs;			//
	mw_base::Bitset<ATTR_INT_COUNT>		__optional_flag_int__;
	//mw_base::Bitset<ATTR_INT64_COUNT>	__optional_flag_int64__;
};

class PacketEnterGameType
{
public:
	static const int ID = PACKET_ENTER_GAME_TYPE;
	template<typename S>
	void map(S& s)
	{
		s << subject;
		s << version;
		s << grade;
		s << chapter;
//		s << classIndex;
	}

	char	subject;	//enum SUBJECT
	char	version;
	char	grade;
	char	chapter;
//	char	classIndex;
};

class PacketEnterGameResult
{
public:
	static const int ID = PACKET_ENTER_GAME_RESULT;
	template<typename S>
	void map(S& s)
	{
		s << subject;
		s << version;
		s << grade;
		s << chapter;
		s << classIndexs;
	}

	char	subject;	//enum SUBJECT
	char	version;
	char	grade;
	char	chapter;
	mw_base::array<char, MAX_CLASS_INDEX>	classIndexs;
};

class AskPKListPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << type;
		s << td;
	}

	static const int ID = PACKET_ASK_PK_LIST;
	BattleTypeInfo type;
	TmpData td;
};

class PKCancelListPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << a;
	}

	static const int ID = PACKET_CANCEL_PK_LIST;
	char a;
};

class AskBattlePKPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		//s << targetQQ;
		s << targetServerid;
		s << pkType;
		s << td;
	}

	static const int ID = PACKET_ASKPK;

	//STRING_OPEN_ID		targetQQ;
	int					targetServerid;
	BattleTypeInfo					pkType;
	TmpData				td;
};

class BattlePKResultPacket
{
public:
	enum RETURN_CODE
	{
		RETURN_CODE_INVALID = -1,
		RETURN_CODE_ERROR,
		RETURN_CODE_SUCCESS,
		RETURN_CODE_ALREADY_IN_BATTLE,			// 已经在战场中了;
		RETURN_CODE_TARGET_ALREADY_IN_BATTLE,	// 目标已经在战场中了;
		RETURN_CODE_TARGET_IS_NULL,				// 目标不存在/不在线;
		RETURN_CODE_DISAGRESS,					// 目标不同意;
		RETURN_CODE_TARGET_IN_PERPARE,			// 目标在随机列表中;
		RETURN_CODE_IN_PERPARE,					// 自己在随机列表中;
		RETURN_CODE_TARGET_IS_MYSELF,			// 自己pk自己;
		RETURN_CODE_COUNT,
	};
public:
	template<typename T>
	void map(T& s)
	{
		s << name;
		s << head;
		s << agency;
		s << robot;
		s << result;
	}

	static const int ID = PACKET_ASKPKRESULT;

	STRING_NICKNAME	name;		// 昵称
	STRING_HEAD_URL	head;		// 头像
	char		agency;		// xxx;
	char		robot;		// 是否是机器人
	int			result;		// 
	
};

class LeaveBattlePacket
{
public:
	template<typename T>
	void map(T& s)
	{
	}
	static const int ID = PACKET_LEAVEBATTLE;
};

class AskUseItemPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << info;
	}

	static const int ID = PACKET_ASK_USE_ITEM;

	int		info;
};

class UseItemReturnPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << info;
	}

	static const int ID = PACKET_BROADCAST_USEITEM;
	int info;
};

class QuestionBankPacket
{
public:
	struct Step
	{
		int				question;

		template<typename T>
		void map(T& s)
		{			
			s << question;
		}
	};
public:
	template<typename T>
	void map(T& s)
	{
		s << type;
		s << td;
		s << steps;
	}

	static const int ID = PACKET_QUESTION_BANK;

	BattleTypeInfo type;
	TmpData	td;
	mw_base::array<Step, MAX_STEP_COUNT> steps;
};

class PKAnswerPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << info;
	}

	static const int ID = PACKET_ANSWER;
	AnswerInfo info;
};

class PKStepPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << myself;
		s << info;
		s << info1;
	}

	static const int ID = PACKET_PKSTEP;
	
	char myself;
	AnswerInfo info;
	AnswerInfo info1;
};

class PKEndPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << firstIsMyself;
		s << success;
		s << success1;
		s << time;
		s << time1;
		s << blood;
		s << blood1;
	}

	static const int ID = PACKET_PKEND;

	// 这里是结果;以后补充.
	unsigned char		firstIsMyself;
	unsigned char		success;
	unsigned char		success1;
	int		time;
	int		time1;
	int		blood;
	int		blood1;
};



class ReportResultPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << type;
		s << subType;
		s << score;
//		s << power;
		s << useItemGuids;
	}

	static const int ID = PACKET_REPORT_RESULT;

	int type;			// 类型;
	int subType;		// 类型;
	int score;			// 得分;
//	int power;			// 扣除体力
	mw_base::array<int, PLAYER_ITEM_COUNT> useItemGuids; // 使用物品情况l
};


class ReportResultRewardPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << rewards;
	}
	static const int ID = PACKET_REPORT_RESULT_REWARD;
	mw_base::array<RewardInfo, MAX_REWARD> rewards;
};

//////////////////////////////////////////////////////////////////////////
// 物品相关
//////////////////////////////////////////////////////////////////////////

class SyncBagPacket
{
public:

	class ItemInfo
	{
	public:
		int		guid;
		int		tableID;
		int		overlap;

		template<typename T>
		void map(T& s)
		{
			s << guid;
			s << tableID;
			s << overlap;
		}
	};


	template<typename T>
	void map(T& s)
	{
		s << items;
	}

	static const int ID = PACKET_SYNC_BAG;

	mw_base::array<ItemInfo, PLAYER_ITEM_COUNT>	items;
};

class AskItemPacket
{
public:
	template<typename T>
	void map(T& s)
	{

	}

	static const int ID = PACKET_ASK_ITEM;

};


class ItemReturnPacket
{
public:
	template<typename T>
	void map(T& s)
	{

	}

	static const int ID = PACKET_ITEM_RETURN;
};



//////////////////////////////////////////////////////////////////////////
// 好友相关
//////////////////////////////////////////////////////////////////////////
class PacketAskQQFriends
{
public:
	template<typename T>
	void map(T& s)
	{
		
	}

	static const int ID = PACKET_ASK_FRIENDS;
};


class SyncFriendPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << friends;
	}

	static const int ID = PACKET_SYNC_FRIEND;

	mw_base::array<QQFriendInfo, QQ_FRIEND_PRE_COUNT> friends;
};

class SyncFriendEndPacket
{
public:
	template<typename T>
	void map(T& s)
	{}

	static const int ID = PACKET_SYNC_FRIEND_END;

};

class FriendDataPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << _fopenid;
		s << data;
	}

	static const int ID = PACKET_S2C_FRIEND_DATA;

	STRING_OPEN_ID	_fopenid;
	char			data;
};

// class FriendPacket
// {
// public:
// 	enum RESULT_TYPE
// 	{
// 		RESULT_TYPE_INVALID = -1,
// 		RESULT_TYPE_ADD_FRIEND,
// 		RESULT_TYPE_DEL_FRIEND,
// 		RESULT_TYPE_COUNT,
// 	};
// 
// 	template<typename T>
// 	void map(T& s)
// 	{
// 		s << type;
// 		s << friendsBitset;
// 		for (int i = 0; i < ADD_FRIEND_COUNT; ++i)
// 		{
// 			if (friendsBitset[i])
// 				s << friends[i];
// 		}
// 	}
// 
// 	static const int ID = PACKET_FRIEND;
// 
// 	void setFriend(int index, int value)
// 	{
// 		friends[index] = value;
// 		friendsBitset.SetFlag(index);
// 	}
// 	bool issetFriend(int index)
// 	{
// 		return friendsBitset[index];
// 	}
// 	const int& getFriend(int index)
// 	{
// 		return friends[index];
// 	}
// 
// 	int type;	// 是添加还是删除;
// 	mw_base::array<int, ADD_FRIEND_COUNT> friends;
// 	mw_base::Bitset<ADD_FRIEND_COUNT> friendsBitset;
// };

class C2SPacketUpdateVigor
{
public:
	static const int ID = PACKET_C2S_UPDATE_VIGOR;

	template<typename T>
	void map(T& s)
	{
		s << num;
	}
	int num;
};

class UseVigorPacket
{
public:

	template<typename T>
	void map(T& s)
	{
		s << num;
	}

	static const int ID = PACKET_USE_VIGOR;
	int num;
};

class QueryRankInfoPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << index;
	}

	static const int ID = PACKET_QUERY_RANK;
	int		index;
};

class RankInfoPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << ranks;
	}

	static const int ID = PACKET_RANK_INFO;
	mw_base::array<RankInfo, MAX_SEND_RANKINFO> ranks;
};


//////////////////////////////////////////////////////////////////////////
//mail info.
class SyncMailPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << mailTitles;
	}

	static const int ID = PACKET_SYNC_MAIL;
	mw_base::array<MailInfo, MAIL_MAX_COUNT> mailTitles;
};

class AddMailPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << info;
	}

	static const int ID = PACKET_ADD_MAIL;
	MailInfo	info;
};

class DelMailPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << id;
	}

	static const int ID = PACKET_DEL_MAIL;
	int		id;
};

class DelMailResultPacket
{
public:
	template<typename T>
	void map(T& s)
	{
		s << id;
	}

	static const int ID = PACKET_DEL_MAIL_RESULT;
	int id;
};

class GetItemsPacket
{
public:
	template<typename T>
	void map(T& s)
	{
// 		s << itemsBitset;
// 		for (int i = 0; i < ITEM_TYPE_COUNT; ++i)
// 		{
// 			if (itemsBitset[i])
// 				s << items[i];
// 		}
	}

// 	void setItem(int index, int value)
// 	{
// 		items[index] = value;
// 		itemsBitset.SetFlag(index);
// 	}
// 	bool issetItem(int index)
// 	{
// 		return itemsBitset[index];
// 	}
// 	const int& getItem(int index)
// 	{
// 		return items[index];
// 	}
	static const int ID = PACKET_GET_ITEMS;
// 	mw_base::array<int, ITEM_TYPE_COUNT> items;
// 	mw_base::Bitset<ITEM_TYPE_COUNT> itemsBitset;
};


class C2SActivationCode
{
public:
	template<typename T>
	void map(T& s)
	{
		s << m_qq;
	}

	static const int ID = PACKET_C2S_ACTIVATION_CODE;
	STRING_QQ	m_qq;
};

class S2CActiveAgencyReward
{
public:
	template<typename T>
	void map(T& s)
	{
		s << _reward;
	}
	static const int ID = PACKET_S2C_ACTIVE_REWARD;
	AgencyReward	_reward;
};
class C2SInNameBrand
{
public:
	template<typename T>
	void map(T& s)
	{
		s << subject;
		s << version;
		s << grade;
		s << chapter;
	}

	static const int ID = PACKET_C2S_IN_NAMEBRAND;
	
	char subject;
	char version;
	char grade;
	char chapter;
};

class C2SOutNameBrand
{
public:
	template<typename T>
	void map(T& s)
	{

	}
	static const int ID = PACKET_C2S_OUT_NAMEBRAND;
};

class C2SNameBrandList
{
public:
	template<typename T>
	void map(T& s)
	{

	}

	static const int ID = PACKET_C2S_NAMEBRAND_LIST;
};

class S2CNameBrandList
{
public:
	template<typename T>
	void map(T& s)
	{
		s << listInfo;
	}

	static const int ID = PACKET_S2C_NAMEBRAND_LIST;
	
	mw_base::array<NetNameBrandInfo, NET_PRE_NAMEBRAND_COUNT> listInfo;
};

class S2CNameBrandListEnd
{
public:
	template<typename T>
	void map(T& s)
	{

	}

	static const int ID = PACKET_S2C_NAMEBRAND_END;
};

class S2CNameBrandListUp
{
public:
	static const int ID = PACKET_S2C_NAMEBRAND_LIST_UP;
	template<typename T>
	void map(T& s)
	{
		s << info;
	}
	NetNameBrandInfo info;
};

class S2CNameBrandListDown
{
public:
	static const int ID = PACKET_S2C_NAMEBRAND_LIST_DOWN;
	template<typename T>
	void map(T& s)
	{
		s << id;
	}
	int id;
};

class S2CNameBrandListBattle
{
public:
	static const int ID = PACKET_S2C_NAMEBRAND_BATTLE_STATUS;
	template<typename T>
	void map(T& s)
	{
		s << id;
		s << status;
	}
	int		id;
	char	status;
};

class S2CPKAskTransmit
{
public:
	template<typename T>
	void map(T& s)
	{
		s << askID;
		s << asker;
		s << bt;
		s << pkType;
		s << td;
	}
	static const int ID = PACKET_S2C_ASKPK_TRANSMIT;

	int					askID;
	STRING_NICKNAME		asker;
	char				bt;
	BattleTypeInfo					pkType;

	TmpData				td;
};

class C2SAnswerTransmit
{
public:
	template<typename T>
	void map(T& s)
	{
		s << isAgree;
		s << askID;
		s << bt;
		s << pkType;
		s << td;
	}
	static const int ID = PACKET_C2S_ANSWER_TRANSMIT;

	char				isAgree;
	int					askID;
	char				bt;
	BattleTypeInfo		pkType;

	TmpData				td;
};

class C2SCreateRoom
{
public:
	template<typename T>
	void map(T& s)
	{
		s << reserved;
	}
	static const int ID = PACKET_C2S_CREATE_ROOM;
	char	reserved;
};

class S2CCreateRoom
{
public:
	template<typename T>
	void map(T& s)
	{
		s << ret;
	}
	static const int ID = PACKET_S2C_CREATE_ROOM;
	char	ret;
};

class C2SEnterRoom
{
public:
	template<typename T>
	void map(T& s)
	{
		s << roomCode;
		s << td;
		s << type;
	}
	static const int ID = PACKET_C2S_ENTER_ROOM;
	int	roomCode;

	TmpData td;
	BattleTypeInfo type;
};

class S2CEnterRoom
{
public:
	template<typename T>
	void map(T& s)
	{
		s << ret;
	}
	static const int ID = PACKET_S2C_ENTER_ROOM;
	char ret;
};

class C2SLeaveRoom
{
public:
	template<typename T>
	void map(T& s)
	{
		s << roomCode;
	}
	static const int ID = PACKET_C2S_LEAVE_ROOM;
	int	roomCode;
};

class S2CLeaveRoom
{
public:
	template<typename T>
	void map(T& s)
	{
		s << ret;
	}
	static const int ID = PACKET_S2C_LEAVE_ROOM;
	char	ret;
};


class C2SThrowDriftBottle
{
public:
	static const int ID = PACKET_C2S_THROW_DRIFT_BOTTLE;
	template<typename T>
	void map(T& s)
	{
		s << index;
		s << infos;
	}

	int index;		//idiom index.
	mw_base::array<mw_base::string32, 7>	infos;
};

class S2CThrowDriftBottle
{
public:
	static const int ID = PACKET_S2C_THROW_DRIFT_RESULT;
	template<typename T>
	void map(T& s)
	{
		s << ret;
	}

	char ret;
};

class C2SPickDriftBottle
{
public:
	static const int ID = PACKET_C2S_PICK_DRIFT_BOTTLE;
	template<typename T>
	void map(T& s)
	{
		s << ret;
	}

	char ret;
};

class S2CPickDriftBottle
{
public:
	static const int ID = PACKET_S2C_PICK_DRIFT_RESULT;
	template<typename T>
	void map(T& s)
	{
		s << id;
		s << index;
		s << infos;
		s << name;
		s << url;
	}
	int id;
	int index;
	mw_base::array<mw_base::string32, 7> infos;
	STRING_NICKNAME	name;
	STRING_HEAD_URL url;
};

class C2SRemarkDriftBottle
{
public:
	static const int ID = PACKET_C2S_REMARK_DRIFT_BOTTLE;
	template<typename T>
	void map(T& s)
	{
		s << id;
		s << c;
	}

	int id;
	char c;
};

class S2CRemarkDriftBottle
{
public:
	static const int ID = PACKET_S2C_REMARK_RESULT;
	template<typename T>
	void map(T& s)
	{
		s << c;
	}
	char c;
};

//////////////////////////////////////////////////////////////////////////
//公会相关的
class C2SCreateGuild
{
public:
	static const int ID = PACKET_C2S_CREATE_GUILD;
	template<typename T>
	void map(T& s)
	{
		s << name;
		s << head;
		s << posID;
		s << key;
	}
	STRING_NICKNAME		name;
	int			head;
	int 			posID;
	string8			key;
};

class S2CCreateGuild
{
public:
	static const int ID = PACKET_S2C_CREATE_GUILD;
	template<typename T>
	void map(T& s)
	{
		s << info;
		s << id;
	}
	char info;
	int  id;
};

class C2SEnterGuild
{
public:
	static const int ID = PACKET_C2S_ENTER_GUILD;
	template<typename T>
	void map(T& s)
	{
		s << id;
	}
	int			id;
};

class S2CEnterGuild
{
public:
	static const int ID = PACKET_S2C_ENTER_GUILD;
	template<typename T>
	void map(T& s)
	{
		s << c;
		s << id;
	}
	char c;
	int id;
};

class C2SLeaveGuild
{
public:
	static const int ID = PACKET_C2S_LEAVE_GUILD;
	template<typename T>
	void map(T& s)
	{
		s << id;
	}
	int id;
};

class S2CLeaveGuild
{
public:
	static const int ID = PACKET_S2C_LEAVE_GUILD;
	template<typename T>
	void map(T& s)
	{
		s << c;
	}
	char c;
};


class S2CGuildDismiss
{
public:
	static const int ID = PACKET_S2C_GUILD_DISMISS;
	template<typename T>
	void map(T& s)
	{
		s << c;
	}
	char c;
};

class C2SGuilds
{
public:
	static const int ID = PACKET_C2S_GUILDS_LIST;
	template<typename T>
	void map(T &s)
	{
	}
};


class S2CGuilds
{
public:
	static const int ID = PACKET_S2C_GUILDS_LIST;
	template<typename T>
	void map(T& s)
	{
		s << guilds;
	}
	mw_base::array<SGuildInfo, 10>		guilds;
};

class S2CGuildsEnd
{
public:
	static const int ID = PACKET_S2C_GUILDS_LIST_END;
	template<typename T>
	void map(T& s)
	{

	}
};

class C2SGuildMembers
{
public:
	static const int ID = PACKET_C2S_MEMBER_LIST;
	template<typename T>
	void map(T& s)
	{
		s << guild_id;
	}
	int			guild_id;
};

class S2CGuildMembers
{
public:
	static const int ID = PACKET_S2C_MEMBER_LIST;
	template<typename T>
	void map(T& s)
	{
		s << members;
	}

	mw_base::array<SGuildMemberInfo , 10>	members;
};

class S2CGuildMembersEnd
{
public:
	static const int ID = PACKET_S2C_MEMBER_LIST_END;
	template<typename T>
	void map(T& s)
	{

	}
};

class C2SGuildApplys
{
public:
	static const int ID = PACKET_C2S_APPLY_MEMBERS;
	template<typename T>
	void map(T& s)
	{

	}
};

class S2CGuildApplys
{
public:
	static const int ID = PACKET_S2C_APPLY_MEMBERS;
	template<typename T>
	void map(T& s)
	{

	}
};

class C2SGuildInfo
{
public:
	static const int ID = PACKET_C2S_GUILD_INFO;
	template<typename T>
	void map(T& s)
	{
		s << id;
	}

	int id;
};

class S2CGuildInfo
{
public:
	static const int ID = PACKET_S2C_GUILD_INFO;
	template<typename T>
	void map(T& s)
	{
		s << info;
	}
	SGuildInfo		info;
};

class S2CMemberExpChange
{
public:
	static const int ID = PACKET_S2C_MEMBER_EXP_CHANGE;
	template<typename T>
	void map(T& s)
	{
		s << memberid;
		s << m_attrFlag;
		for (int i = 0; i < GUILD_MEMBER_ATTR_COUNT; ++i)
		{
			if (!m_attrFlag[i])
				continue;
			s << m_attr[i];
			m_attrFlag.ClearFlag(i);
		}
	}
	int		memberid;
	
	int		getAttr(int index) {return m_attr[index];}
	bool	isAttr(int index) {return m_attrFlag[index];}
	void	setAttr(int index, int v) {m_attrFlag.SetFlag(index); m_attr[index]=v;}
private:
	mw_base::array<int, GUILD_MEMBER_ATTR_COUNT> m_attr;
	mw_base::Bitset<GUILD_MEMBER_ATTR_COUNT> m_attrFlag;
};

class S2CGuildDesc
{
public:
	static const int ID = PACKET_S2C_GUILD_DESC;
	template<typename T>
	void map(T& s)
	{
		s << desc;
	}
	mw_base::string512 desc;
};

class S2CGuildNameHeadPos
{
public:
	static const int ID = PACKET_S2C_GUILD_NAME_HEAD_POS;
	template<typename T>
	void map(T& s)
	{
		s << name;
		s << head;
		s << posID;
	}

	STRING_NICKNAME name;
	int		head;
	int 		posID;
};

class C2SInGuildPK
{
public:
	static const int ID = PACKET_C2S_IN_GUILD_PK;
	template<typename T>
	void map(T& s)
	{

	}
};

class C2SGuildNotify
{
public:
	static const int ID = PACKET_C2S_GUILD_NOTIFY;
	template<typename T>
	void map(T& s)
	{
		s << ss;
	}
	string128 ss;
};

class C2SGuildChangeInfo
{
public:
	static const int ID = PACKET_C2S_GUILD_CHANGE_INFO;
	template<typename T>
	void map(T& s)
	{
		s << name;
		s << head;
		s << posID;
	}

	STRING_NICKNAME name;
	int		head;
	int 		posID;
};

class C2SGuildChangeDesc
{
public:
	static const int ID = PACKET_C2S_CHANGE_GUILD_DESC;
	template<typename T>
	void map(T& s)
	{
		s << desc;
	}
	mw_base::string512 desc;
};

class C2SGuildChangeProperty
{
public:
	static const int ID = PACKET_C2S_MEMBER_POWER;
	template<typename T>
	void map(T& s)
	{
		s << memberid;
		s << power;
	}
	int memberid;
	int power;
};

class S2CInGuildPK
{
public:
	static const int ID = PACKET_S2C_IN_GUILD_PK;
	template<typename T>
	void map(T& s)
	{

	}
};

class C2SOutGuildPK
{
public:
	static const int ID = PACKET_C2S_OUT_GUILD_PK;
	template<typename T>
	void map(T& s)
	{

	}
};

class S2COutGuildPK
{
public:
	static const int ID = PACKET_S2C_OUT_GUILD_PK;
	template<typename T>
	void map(T& s)
	{

	}
};

class C2SGuildKick
{
public:
	static const int ID = PACKET_C2S_GUILD_KICK;
	template<typename T>
	void map(T& s)
	{
		s << targetID;
	}
	int targetID;
};

class S2CGuildAddMember
{
public:
	static const int ID = PACKET_S2C_ADD_MEMBER;
	template<typename T>
	void map(T& s)
	{
		s << targetID;
	}
	int		targetID;
};

class S2CGuildDelMember
{
public:
	static const int ID = PACKET_S2C_DEL_MEMBER;
	template<typename T>
	void map(T& s)
	{
		s << targetID;
	}
	int		targetID;
};

class C2SGuildUpgrade
{
public:
	static const int ID = PACKET_C2S_GUILD_UPGRADE;
	template<typename T>
	void map(T& s)
	{

	}
};

class C2SActivityListInfo
{
public:
	static const int ID = PACKET_C2S_ACTIVITY_LIST;
	template<typename T>
	void map(T &s)
	{
	//	s << activitys;
	}
		
};

class S2CActivityListInfo
{
public:
	static const int ID = PACKET_S2C_ACTIVITY_LIST;
	template<typename T>
	void map(T& s)
	{
		s << activitys;
	}	
	mw_base::array<int, MAX_ACTIVITY_COUNT>	activitys;
};

class C2SActivityDraw
{
public:
	static const int ID = PACKET_C2S_ACTIVITY_DRAW;
	template<typename T>
	void map(T& s)
	{
		s << activityID;
		s << rankIndex;
	}
	int activityID;
	int rankIndex;
};

class S2CActivityDraw
{
public:
	static const int ID = PACKET_S2C_ACTIVITY_DRAW;
	template<typename T>
	void map(T& s)
	{}
};


class C2SNotifyMsg
{
public:
	static const int ID = PACKET_C2S_NOTIFY_MSG;
	
	template<typename T>
	void map(T& s)
	{
		s << type;
		s << msg;
	}
	char			type;
	mw_base::string1k 	msg;
};

class S2CNotifyMsg
{
public:
	static const int ID = PACKET_S2C_NOTIFY_MSG;

	template<typename T>
	void map(T& s)
	{
		s << type;
		s << msg;
	}

	char 			type;
	mw_base::string1k	msg;
};

class C2SChat
{
public:
	static const int ID = PACKET_C2S_CHAT;
	template<typename T>
	void map(T& s)
	{
		s << type;
		s << player_id;
		s << msg;
	}
	int		type;
	int 	player_id;
	mw_base::string1k	msg;
};

class S2CChat
{
public:
	static const int ID = PACKET_S2C_CHAT;
	template<typename T>
	void map(T& s) 
	{
		s << player_id;
		s << msg;
		s << head;
		s << guildHeadID;
		s << name;
	}

	int 	player_id;
	STRING_NICKNAME name;
	STRING_HEAD_URL head;
	int		guildHeadID;
	mw_base::string1k 	msg;
};

class C2SEnterGongFang
{
public:
	static const int ID = PACKET_C2S_ENTER_GONGFANG;
	template<typename T>
	void map(T& s)
	{
		s << c;
	}
	char c;	//是打开还是关闭;
};

// class S2CEnterGongFang
// {
// public:
// 	static const int ID = PACKET_S2C_ENTER_GONGFANG;
// 	template<typename T>
// 	void map(T& s)
// 	{
// 	
// 	}
// };

class C2SBeginGongFang
{
public:
	static const int ID = PACKET_C2S_BEGIN_GONGFANG;
	template<typename T>
	void map(T& s)
	{}
};


class S2CBeginGongFang
{
public:
	static const int ID = PACKET_S2C_BEGIN_GONGFANG;
	template<typename T>
	void map(T& s)
	{
		s << targetID;
		s << name;
		s << head;
		s << homeLevel;
		s << homeTime;
		s << infos;
	}

	int targetID;
	STRING_NICKNAME	name;
	STRING_HEAD_URL	head;
	int				homeLevel;
	long long		homeTime;
	mw_base::array<GongFangTowerInfo, TOWER_TYPE_COUNT> infos;
};

class C2SStartGongFang
{
public:
	static const int ID = PACKET_C2S_START_GONGFANG;
	template<typename T>
	void map(T& s)
	{
		s << targetID;
	}

	int targetID;
};

class C2SFinishGongFang
{
public:
	static const int ID = PACKET_C2S_FINISH_GONGFANG;
	template<typename T>
	void map(T& s)
	{
		s << result;
		s << gold;
		s << exp;
		s << honor;
		s << homeItem;
		s << towersInfo;
	}

	int result;		//是否摧毁
	int gold;		//gold
	int exp;		//exp
	int	honor;		//荣誉值
	int homeItem;		//水晶碎片：
	mw_base::array<int, TOWER_TYPE_COUNT> towersInfo;
};

class S2CFinishGongFang
{
public:
	static const int ID = PACKET_S2C_FINISH_GONGFANG;
	template<typename T>
	void map(T& s)
	{
	}
};

class C2SGongFangChangeType
{
public:
	static const int ID = PACKET_C2S_CHANGE_GONGFANG_TYPE;
	template<typename T>
	void map(T& s)
	{
		s << id;
		s << type;
	}

	int		id;
	int		type;
};

class C2SGongFangInfos
{
public:
	static const int ID = PACKET_C2S_GONGFANG_INFO;
	template<typename T>
	void map(T& s)
	{

	}
};

class S2CGongFangInfos
{
public:
	static const int ID = PACKET_S2C_GONGFANG_INFO;
	template<typename T>
	void map(T& s)
	{
		s << homeLevel;
		s << homeTime;
		s << towers;
	}

	int homeLevel;
	long long homeTime;
	mw_base::array<TowerInfo, TOWER_TYPE_COUNT>	towers;
};

class C2SGongFangAdd
{
public:
	static const int ID = PACKET_C2S_GONGFANG_ADD;
	template<typename T>
	void map(T& s)
	{
		s << towers;
	}

	mw_base::array<TowerInfo, TOWER_TYPE_COUNT>	towers;
};

class C2SGongFangReceive
{
public:
	static const int ID = PACKET_C2S_GONGFANG_RECEIVE;
	template<typename T>
	void map(T& s)
	{
		s << towerID;
	}

	int towerID;
};

class C2SGongFangBeginUpgrade
{
public:
	static const int ID = PACKET_C2S_GONGFANG_BEGIN_UPGRADE;
	template<typename T>
	void map(T& s)
	{
		s << _type;
		s << time;
	}

	int _type;
	int time;			//应该是秒数
};

class C2SGongFangUpgrade
{
public:
	static const int ID = PACKET_C2S_GONGFANG_UPGRADE;
	template<typename T>
	void map(T& s)
	{
		s << subType;

	}

	int subType;		//-1 水晶，其他的就是塔的类型 TOWER_TYPE
};

class C2SSingleData
{
public:
	static const int ID = PACKET_C2S_SINGLE_DATA;

	template<typename T>
	void map(T& s)
	{
		s << type;
		s << param1;
		s << param2;
		s << param3;
	}

	int		type;
	int		param1;
	int		param2;
	int		param3;
};

class C2SAskVigor
{
public:
	static const int ID = PACKET_C2S_ASK_VIGOR;
	template<typename T>
	void map(T& s)
	{
		s << targetID;
	}

	int targetID;
};

class C2SAskVigorResult
{
public:
	static const int ID = PACKET_C2S_ASK_VIGOR_RESULT;
	template<typename T>
	void map(T& s)
	{
		s << result;
		s << askerID;
	}
	int result;
	int askerID;
};

class S2CHaveNews
{
public:
	static const int ID = PACKET_S2C_HAVE_NEWS;
	template<typename T>
	void map(T& s)
	{
		s << type;
	}
	int type;	//NEWS_TYPE
};


class PacketSyncGuildAttr
{
public:

	const int&	getAttr	(const int index) const	{ return m_attr[index];	}
	bool	isSetAttr(const int index) { return __optional_flag__attr[index]; }
	void	setAttr	(const int index, const int& value)	{ m_attr[index] = value; __optional_flag__attr.set(index);	}

	static const int ID = PACKET_SYNC_GUILD_DATA;

	template <typename StreamerT>
	void map(StreamerT& s)
	{
		s << __optional_flag__attr;
		for (int i = 0; i < m_attr.capacity(); ++i)
		{
			if (__optional_flag__attr[i])
				s << m_attr[i];
		}
	}

private:
	mw_base::array<int, GUILD_ATTR_COUNT>	m_attr;			//属性数组
	mw_base::Bitset<GUILD_ATTR_COUNT>	__optional_flag__attr;
};

class PacketSyncGuildMemberData
{
public:
	static const int ID = PACKET_SYNC_GUILD_MEMBER_DATA;

	template<typename T>
	void map(T& s)
	{
		s << exp;
		//s << contribution;
	}
	int			exp;
	//int			contribution;
};

class C2SAskGuildWar
{
public:
	static const int ID = PACKET_C2S_ASK_GUILD_BOSS;

	template<typename T>
	void map(T& s)
	{
		s << warID;
	}

	int warID;
};

class S2CRetGuildWar
{
public:
	static const int ID = PACKET_S2C_RET_GUILD_BOSS;

	template<typename T>
	void map(T& s)
	{
		s << hp;
		s << index;
	}

	int		hp;
	int		index;
};

class C2SReportGuildWar
{
public:
	static const int ID = PACKET_C2S_REPORT_GUILD_BOSS;
	template<typename T>
	void map(T& s)
	{
		s << warID;
		s << hp;
	}

	int		warID;
	int		hp;
};

class C2SLeaveGuildWar
{
public:
	static const int ID = PACKET_C2S_LEAVE_GUILD_BOSS;
	template<typename T>
	void map(T& s)
	{

	}
};

class C2SGuildBossRank
{
public:
	static const int ID = PACKET_C2S_GUILD_BOSS_RANK;

	template<typename T>
	void map(T& s)
	{
		s << warID;
		s << type;
	}
	int warID;
	int type;		//1.是前几名的榜,2是guild榜，3是自己前后几名的榜(目前不支持)
};

class S2CGuildBossRank
{
public:
	static const int ID = PACKET_S2C_GUILD_BOSS_RANK;

	template<typename T>
	void map(T& s)
	{
		s << warID;
		s << type;
		s << vec;
	}
	int warID;
	int	type;	// 同上;
	mw_base::array<GuildRankInfo, 50> vec;
	GuildRankInfo myself;
};


class C2SAskGuildTargetOp
{
public:
	static const int ID = PACKET_C2S_ASK_GUILD_TARGET_OP;

	template<typename T>
	void map(T& s)
	{
		s << type;
	}

	char type; //1 ask target, 2,ask be attack, 3, ask rank;
};

class S2CAskGuildTarget
{
public:
	static const int ID = PACKET_S2C_ASK_GUILD_TARGET;

	template<typename T>
	void map(T& s)
	{
		s << targetinfo;
	}

	GuildTargetInfo targetinfo;
};

class S2CAskGuildBeAttackList
{
public:
	static const int ID = PACKET_S2C_ASK_GUILD_BEATTACK_LIST;
	
	template<typename T>
	void map(T& s)
	{
		s << targets;
	}

	mw_base::array<GuildTargetInfo, 20> targets;
};

class S2CAskGuildTargetRank
{
public:
	static const int ID = PACKET_S2C_ASK_GUILD_TARGET_RANK;

	template<typename T> void map(T& s)
	{
		s << rankers;
	}

	mw_base::array<GuildTargetRankInfo, 50> rankers;
};

class C2SReportGuildTargetResult
{
public:
	static const int ID = PACKET_C2S_REPORT_GUILD_TARGET_RESULT;

	template<typename T> void map(T& s)
	{
		s << target_id;
		s << score;
	}

	int target_id;
	int score;
};

class C2SAskGuildTargetRevenge
{
public:
	static const int ID = PACKET_C2S_ASK_GUILD_TARGET_REVENGE;
	template<typename T> void map(T& s)
	{
		s << target_id;
	}

	int target_id;
};

class C2SAskJinKuang
{
public:
	static const int ID = PACKET_C2S_ASK_JINKUANG;
	template<typename T> void map(T& s)
	{
		s << type;
	}

	char type;	//1.查询，2收割;
};

class S2CAskJinKuang
{
public:
	static const int ID = PACKET_S2C_ASK_JINKUANG;
	template<typename T> void map(T& s)
	{
		s << currentTime;
		s << beforTime;
	}

	long long currentTime;
	long long beforTime;
};

class S2CSyncCardbag
{
public:
	static const int ID = PACKET_S2C_CARD_BAG;
	template<typename T>
	void map(T & s)
	{
		s << cards;
	}

	mw_base::array<stCard, MAX_CARD_COUNT> cards;
};

class C2SAddCard
{
public:
	static const int ID = PACKET_C2S_ADD_CARD;

	template<typename T>
	void map(T& s)
	{
		s << cards;
	}

	//一次性最大MAX_CARD_COUNT个添加,
	mw_base::array<stCard, MAX_CARD_COUNT> cards;
};

class C2SReplaceCard
{
public:
	static const int ID = PACKET_C2S_REPLACE_CARD;
	template<typename T>
	void map(T& s)
	{
		s << oldCard;
		s << newCard;
	}

	stCard	oldCard;
	stCard	newCard;
};

class C2SSetFightCard
{
public:
	static const int ID = PACKET_C2S_SET_FIGHT_CARD;
	template<typename T>
	void map(T& s)
	{
		s << cards;
	}

	//一起设置CARDS_COUNT个
	mw_base::array<int, CARDS_COUNT> cards;
};

class C2SSettingCard
{
public:
	static const int ID = PACKET_C2S_SETTING_CARD;
	template<typename T>
	void map(T& s) 
	{
		s << cards;
	}

	//设置一个card的信息;
	//不确定，先给个最大的设置情况;
	mw_base::array<stCard, MAX_CARD_COUNT> cards;
};
}
#endif
