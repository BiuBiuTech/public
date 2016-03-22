#ifndef __SERVER_DEF_HEADER__
#define __SERVER_DEF_HEADER__

#include "../BaseSupport/string.h"
#include "../BaseSupport/array.h"
namespace tech
{
	typedef int			role_t;
	typedef int			guild_t;

	// 数据库最大的版本号
	const int		SQL_MAX_UPDATE_VERSION		= 1000000;
	//货币相关
	const long long MONEY_LIMIT					= 1000000000;
	// report timer
	const int		REPORT_TIME_DELAY			= 100000;

#if WIN32
	const int kPlayerSize				= 126;
	const int kCacheSize				= 126;
	const int MAX_FRIEND_COUNT			= 20; // 500;
#else
	const int kPlayerSize				= 10000;
	const int kCacheSize				= 20000;
	const int MAX_FRIEND_COUNT			= 20; // 500;
#endif

	// for tech.
	const int OPEN_ID_LEN				= 32;
	const int OPEN_KEY_LEN				= 32;
	const int NICK_NAME_LEN				= 32;
	const int QQ_LEN					= 32;
	typedef mw_base::string<OPEN_ID_LEN+1>		STRING_OPEN_ID;
	typedef mw_base::string<OPEN_KEY_LEN+1>		STRING_OPEN_KEY;
	typedef mw_base::string<NICK_NAME_LEN+1>	STRING_NICKNAME;
	typedef mw_base::string128					STRING_HEAD_URL;
	typedef mw_base::string<QQ_LEN>				STRING_QQ;

	// for battle.
	const int BATTLE_PLAYER_COUNT		= 2;
	const int BATTLE_COUNT				= kPlayerSize;
	const int BATTLE_PREPARE_TIME		= 5000;

	const int BATTLE_ROBOT_ANSWER_TIMT	= 10000;
	const int MAX_STEP_COUNT			= 20;
	const int ALL_QUESION_COUNT			= MAX_STEP_COUNT;

	const int MAX_ANSWERS				= 3;
	const int PK_MAX_TIMES				= 120000;				// 2分钟
	const int BATTLE_MAX_TIMES			= 300000;				// 5分钟;

	// for items.
	const int PLAYER_ITEM_COUNT			= 200;
	const int SERVER_ITEM_COUNT			= kPlayerSize*PLAYER_ITEM_COUNT;

	// for friends.
	const int ADD_FRIEND_COUNT			= 200;
	const int QQ_FRIEND_PRE_COUNT		= 20;

	// 最多奖励类型;
	const int MAX_REWARD				= 5;

	// for rank.
	const int MAX_SEND_RANKINFO			= 11;			// 排行榜一次发送多少个;
	const int MAX_RANK_COUNT			= 10000;		// 排行榜内存缓存数量

	// for vigor
	const int VIGOR_TIME				= 360;		// vigor恢复时间;360s
	const int VIGOR_COUNT				= 1;			// vigor恢复点数;
	const int MAX_VIGOR					= 12;			// 玩家最大vigor.

	//每章有多少节
	const int MAX_CLASS_INDEX			= 10;

	//公会相关
	const int MAX_MEMBER_COUNT			= 200;
	const int PER_MEMBER_COUNT			= 20;
	const int PER_GUILD_COUNT			= 20;
	const int GUILD_MAX_MEMBER			= 50;


	// activity...
	const int MAX_ACTIVITY_COUNT			= 50;
	// activity...
	

	// 好友操作返回信息枚举
	enum FRIEND_RESULT_TYPE
	{
		FRIEND_RESULT_TYPE_INVALID = -1,

		FRIEND_RESULT_TYPE_ERROE,			//未知错误.
		FRIEND_RESULT_TYPE_SUCCESS,
		FRIEND_RESULT_TYPE_ALREADY_HAVE,	//已经有了

		FRIEND_RESULT_TYPE_COUNT,
	};


	// 错误信息
	enum ERROE_CODE
	{
		ERROR_CODE_INVALID = -1,

		ERROR_CODE_VERSION_ERROR,			// 版本号不对应;
		ERROR_LOGIN_OPENID_INVALID,			// 登录的时候openid不合法,必须是32个字母或者数字组成;
		ERROR_LOGIN_NICKNAME_URL_NULL,		// nickname or head url is null.

		ERROR_CODE_ALREADY_BATTLE,			// 已经在战斗内;
		ERROR_CODE_BATTLE_MYSELF,			// 不能与自己pk;
		
		ERROR_CODE_ORG_NO_THIS_QQ,			// 机构中没有这个qq;也许已经被注册了.
		ERROR_CODE_ORG_ALREAY_HAS,			// 已经验证过.
		ERROR_CODE_ORG_QQ_EMPTY,			// 传过来的qq是空值;

		ERROR_CODE_NB_SELECT_COUNT_ERROR,
		ERROR_CODE_NB_ALREADY_IN,

		ERROR_CODE_HAS_GUILD_CREATE,		//已经有公会了，不能在创建了
		ERROR_CODE_HAS_GUILD_NAME,
		ERROR_CODE_KEY_NOT_HAVE,			//不存在
		ERROR_CODE_KEY_NOT_USEFUL,			//当前key 不存在了.
		ERROR_CODE_HAS_GUILD_ENTER,			//已经有公会了，不能在加入了
		ERROR_CODE_NOT_FIND_GUILD,			//加入的时候，没有找到这个公会;
		ERROR_CODE_MEMBER_COUNT_MAX,		//公会玩家达到最大的数量了。
		ERROR_CODE_NOT_IN_GUILD,			//删除.退出公会的时候，发现自己不再公会
		ERROR_CODE_NOT_FIND_IN_GUILD,		//删除的时候，发现公会里没有他;
		ERROR_CODE_GUILD_POWER_LIMIT,		//权限不够
		ERROR_CODE_GUILD_POWER_ERROR,		//设置的权限不对

		ERROR_CODE_IN_NAMEBRAND_GUILDPK,	//发送in guild pk的时候，发现玩家在namebrand中，这两个互斥的;
		ERROR_CODE_NOT_IN_GUILDPK,			//没有在guild pk里面，所以发送outGuildPk就是有问题.

		ERROR_CODE_ACTIVITY_DRAWED,		//has draw already!!!

		ERROR_CODE_ENTER_GONGFANG_ERROR,	//正在接受攻击;
		ERROR_CODE_BEGIN_GONGFANG_NO_PLAYER,	//没有找到合适的玩家;
		ERROR_CODE_IS_GONGFANG_ALREADY,		//正在攻击别人还没结束

		ERROR_CODE_CHAT_MSG_NULL,
		ERROR_CODE_GUILD_NAME_IS_NULL,
		ERROR_CODE_ASK_VIGOR_ALREADY,		//已经找此玩家索求过体力了;
		ERROR_CODE_ASK_VIGOR_GUILD_NOT_SAME,

		ERROR_CODE_UPGRADE_BEFORE_ING,		//前一个正在升级
		ERROR_CODE_UPGRADE_TIME_LIMIT,		//升级等级的时候时间没到;
		ERROR_CODE_UPGRADE_NOT_SAME_TYPE,	//类型不同，与当前升级的时间倒计时的类型 不同;
		ERROR_CODE_UPDATE_VIGOR_TIME_LIMIT,	//时间没到。
		ERROR_LOGIN_NICKNAME_INVALID,		//昵称有非法字符\,%,",',;,<,>,?,\n,\r,0

		// for guildwar
		ERROR_GUILDWAR_HAS_IN_WAR,
		ERROR_GUILDWAR_NOT_HAS_IN_WAR,

		ERROR_GUILD_REVENGE_NO_TARGET,		//没有找到匹配对象

		ERROR_CARD_ADD_TO_MAX,				//已经最大值了
		ERROR_CARD_NO_OLD_CARD,				//替换的时候发现没有新的卡.
		ERROR_CODE_COUNT,
	};

	// success code.
	enum SUCCESS_CODE
	{
		SUCCESS_CODE_INVALID = -1,
		SUCCESS_CODE_IN_NAMEBRAND,
		SUCCESS_CODE_OUT_NAMEBRAND,
		SUCCESS_CODE_COUNT_NOT_USE,

		SUCCESS_CODE_ENTER_GONGFANG,		//进入攻防(打开攻防对话框)成功;
		SUCCESS_CODE_LEAVE_GONGFANG,		//关闭对话框;.

		SUCCESS_CODE_CREATE_GUILD,
		SUCCESS_CODE_ENTER_GUILD,
		SUCCESS_CODE_GUILD_CHANGE_INFO,
		SUCCESS_CODE_GUILD_CHANGE_POWER,
		SUCCESS_CODE_GUILD_KICK,			//剔除成功
		SUCCESS_CODE_ADD_GONGFANG,			//添加攻防成功

		SUCCESS_CODE_SINGLE_DATA,
		SUCCESS_CODE_RECEIVE_GONGFANG,		//收取成功
		SUCCESS_CODE_SYNC_DATA,				//同步数据成功
		SUCCESS_CODE_SYNC_MONEY_DATA,		//同步money属性成功;
		SUCCESS_CODE_SYNC_GUILD_DATA,		//学团数据同步成功
		SUCCESS_CODE_SYNC_GUILD_MEMBER_DATA,//军团成员属性修改;
		SUCCESS_CODE_GUILD_UPGRADE,			//学团升级成功
		SUCCESS_CODE_GONGFANG_BEGIN_UPGRADE,//开始设置攻防升级时间成功
		SUCCESS_CODE_GONGFANG_UPGRADE,		//攻防升级成功

		SUCCESS_CODE_UPDATE_VIGOR,			//更新成功
		SUCCESS_CODE_ASK_GUILD_WAR,


		SUCCESS_REPORT_GUILD_TARGET_RESULT,	//学团攻防报告结果成功;
		SUCCESS_GUILD_TARGET_REVENGE,		//学团攻防报复;

		SUCCESS_JINKUANG_OK,				//金矿收集ok.

		SUCCESS_CODE_CHANGENAME,			//修改昵称成功
		SUCCESS_CODE_CHANGEICON,			//修改icon成功

		SUCCESS_CODE_ADD_CARD,				//加卡成功;
		SUCCESS_CODE_REPLACE_CARD,			//替换卡成功;
		SUCCESS_CODE_SETTING_CARD,			//设置卡成功;

		SUCCESS_CODE_COUNT,
	};

	// 物品类型
	enum ITEM_TYPE
	{
		ITEM_TYPE_INVALID = -1,

		ITEM_TYPE_ZOOM,		// 放大镜.
		ITEM_TYPE_DOOM,		// 炸弹.
		ITEM_TYPE_OVERTIME,	// 延迟时间.
		ITEM_TYPE_INFO,		// 提示类型.

		ITEM_TYPE_COUNT,
	};


	// 玩家属性;
	enum ATTR
	{
		ATTR_INVALID = -1,

		ATTR_ACHIEVEMENT,		   //成就
		ATTR_CONTRIBUTION,		   //贡献度;
		ATTR_ALLSCORE,			   //累计得分
		ATTR_SUCCESS,			   //胜利次数
		ATTR_FAILURE,			   //失败次数

		ATTR_COUNT,
	};

	struct QQFriendInfo
	{
		template<typename T>
		void map(T& s)
		{
			s << openid;
			s << nickname;
			s << headurl;
			s << param1;
		}

		STRING_OPEN_ID	openid;
		STRING_NICKNAME	nickname;
		STRING_HEAD_URL	headurl;
		char			param1;
	};

// 	struct FriendDBInfo
// 	{
// 		FriendDBInfo()
// 		{
// 			param1 = 0;
// 		}
// 
// 		template<typename T>
// 		void map(T& s)
// 		{
// 			s << qq;
// 			s << param1;
// 		}
// 
// 		STRING_OPEN_ID	qq;
// 		int				param1;			// 
// 		long long		achievement;	//成就
// 		long long		contribution;	//贡献度;
// 		int			winRate;		//胜率;
// 		bool			online;
// 	};

	//////////////////////////////////////////////////////////////////////////
	// for battle...//////////////////////////////////////////////////////////
	enum SINGLE_TYPE
	{
		SINGLE_TYPE_INVALID = -1,
		SINGLE_TYPE_A,
		SINGLE_TYPE_B,
		SINGLE_TYPE_COUNT,
	};

	enum BATTLE_TYPE
	{
		BATTLE_TYPE_INVALID = -1,

		BATTLE_TYPE_LIST,		// LIST匹配
		BATTLE_TYPE_QUERY,		// 请求的pvp;
		BATTLE_TYPE_ROOM,		// 创建房间类型;
		BATTLE_TYPE_NAMEBRAND,	// 撕名牌
		BATTLE_TYPE_GUILD,		// GUILD相关
		BATTLE_TYPE_CHESS,		// 化学题目;
		BATTLE_TYPE_GUILD_WAR,	//guild_war;

		BATTLE_TYPE_COUNT,
	};

	enum BATTLE_RESULT
	{
		BATTLE_RESULT_FAILED = 0,
		BATTLE_RESULT_SUCCESS,
		BATTLE_RESULT_DRAWN,
	};

	enum PK_TYPE
	{
		PK_TYPE_INVALID = -1,

		PK_TYPE_CHEMISTRY,

		PK_TYPE_COUNT,
	};

	enum PK_ITEM
	{
		PK_ITEM_INVALID = -1,

		PK_ITEM_CHOICE,		//选择题
		PK_ITEM_ZHAONIMEI,	//找你妹

		PK_ITEM_COUNT,
	};

	struct AnswerInfo 
	{
		AnswerInfo():param1(0), param2(0), param3(0){}
		int		param1;
		int		param2;
		int		param3;

		template<typename T>
		void map(T& s)
		{
			s << param1;
			s << param2;
			s << param3;
		}

		void clear()
		{
			param1 = param2 = param3 = 0;
		}
	};

	enum REWARD_MAIN
	{
		REWARD_MAIN_ITEM,
		REWARD_MAIN_MONEY,
		REWARD_MAIN_ATTR,
	};

	struct RewardInfo
	{
		REWARD_MAIN main;
		int			param1;
		int			param2;
		int			param3;

		template<typename T>
		void map(T& s)
		{
			int a = main;
			s <<a;
			s << param1;
			s << param2;
			s << param3;
		}
	};

	// for battle...///////////////////////////////////////////////////////////

	// for rank...///////////////////////////////////////////////////////////
	enum RANK_TYPE
	{
		RANK_TYPE_INVALID = -1,

		RANK_TYPE_0,
		RANK_TYPE_1,
		RANK_TYPE_2,
		RANK_TYPE_3,
		RANK_TYPE_4,		

		RANK_TYPE_COUNT,
	};
	struct RankInfo 
	{
		template<typename T>
		void map(T& s)
		{
			s << useID;
			s << rankID;
			s << agency;
			s << score;
			s << nickname;
		}

		int useID;
		int rankID;	// 排行id.
		char agency;	// 
		long long score;	// 分数;
		STRING_NICKNAME nickname;// 昵称
	};
	// for rank...///////////////////////////////////////////////////////////
	
	// for mail...///////////////////////////////////////////////////////////
	const int MAIL_MAX_COUNT = 20;

	enum MAIL_TYPE
	{
		MAIL_TYPE_INVALID=-1,

		MAIL_TYPE_SYSTEM,		// 系统类型
		MAIL_TYPE_PK,			// pk类型

		MAIL_TYPE_COUNT,
	};

	struct MailInfo
	{
		template<typename T>
		void map(T& s)
		{
			s << id;
			s << byType;
			s << content;
		}

		int					id;
		unsigned char		byType;
		string512			content;
	};
	// for mail...///////////////////////////////////////////////////////////

	// for agency //////////////////////////////////////////////////////////////////////////
	enum AGENCY_TYPE
	{
		AGENCY_TYPE_INVALID = -1,

		AGENCY_TYPE_NORMAL,
		AGENCY_TYPE_NUM1,			// 未名

		AGENCY_TYPE_COUNT,
	};

	struct AgencyReward
	{
		template<typename T>
		void map(T& s)
		{
			s << org;
			s << exp;
			s << money;
			s << item1;
			s << item2;
			s << item3;
		}
		char	org;
		int		exp;
		int		money;
		int		item1;
		int		item2;
		int		item3;
	};
	// for agency //////////////////////////////////////////////////////////////////////////

	// for namebrand...///////////////////////////////////////////////////////////
	const int NAMEBRAND_EVERY_COUNT = 1;
	const int NET_PRE_NAMEBRAND_COUNT = 20;

	class NetNameBrandInfo
	{
	public:
		template<typename T>
		void map(T& s)
		{
			s <<	id;
			s <<	count;
			s <<	org;
			s <<	nickName;
			s <<	headUrl;
			s <<	isBattle;
		}

		int					id;
		int					count;
		char				org;
		STRING_NICKNAME		nickName;
		STRING_HEAD_URL		headUrl;		
		char				isBattle;
	};

	class NameBrandRankInfo
	{
	public:
		template<typename T>
		void map(T& s)
		{
			s << useID;
			s << agency;
			s << namebrands;
			s << nickName;
			s << headUrl;
		}
		int					useID;
		char				agency;	// 
		int					namebrands;
		STRING_NICKNAME		nickName;
		STRING_HEAD_URL		headUrl;
	};
	// for namebrand...///////////////////////////////////////////////////////////


	//
	enum SUBJECT
	{
		SUBJECT_INVALID = -1,
		SUBJECT_CHEMISTRY,
		SUBJECT_COUNT,
	};


	struct TmpData
	{
		char subject;
		char version;
		char grade;
		char chapter;
		char classIdx;
		TmpData() {clear();}
		void clear()
		{
			subject = 0;
			version = 0;
			grade = 0;
			chapter = 0;
			classIdx = 0;
		}

		void set(TmpData& dt)
		{
			subject = dt.subject;
			version = dt.version;
			grade = dt.grade;
			chapter = dt.chapter;
			classIdx = dt.classIdx;
		}
		int toKey()
		{
			return subject*1000000+version*10000+grade*100+chapter;
		}

		template<typename T>
		void map(T& s)
		{
			s << subject;
			s << version;
			s << grade; 
			s << chapter;
			s << classIdx;
		}
	};

	struct BattleTypeInfo
	{
		char	_type;
		int		_min;
		int		_max;
		template<typename T>
		void map(T& s)
		{
			s << _type;
			s << _min;
			s << _max;
		}
	};

	//公会 
	enum GUILD_POWER
	{
		GUILD_POWER_NORMAL		= 1,
		GUILD_POWER_CHANGNAME	= 1 << 1,
		GUILD_POWER_APPLY		= 1<< 2,
		GUILD_POWER_KICK		= 1 << 3,
		GUILD_POWER_CHANGEPOWER = 1 << 4,
		GUILD_POWER_NOTICE		= 1 << 5,
		GUILD_POWER_BUY_BAG		= 1 << 6,
		GUILD_POWER_GRANT		= 1 << 7,		//拨款
	};
	struct SGuildInfo
	{
		int				id;
		int				creater;
		STRING_NICKNAME	name;
		int				head;
		int				exp;
		short			members;
		short			maxMember;
		
		int				gold;
		int 				diamond;//...
		int				pos;
		mw_base::string512		desc;
		int				attr1;
		int				attr2;
		int				attr3;
		int				attr4;
		template<typename T>
		void map(T& s)
		{
			s << id;
			s << name;
			s << head;
			s << exp;
			s << members;
			s << maxMember;
			s << gold;
			s << diamond;
			s << creater;
			s << pos;
			s << desc;
			s << attr1;
			s << attr2;
			s << attr3;
			s << attr4;
		}
	};

	struct SGuildMemberInfo 
	{
		int				id;
		STRING_NICKNAME	name;
		STRING_HEAD_URL	head;
		int				contribution;
		int				level;
		int				power;
		int				honor;

		template<typename T>
		void map(T& s)
		{
			s << id;
			s << name;
			s << head;
			s << contribution;
			s << level;
			s << power;
			s << honor;
		}
	};

	enum PLAYER_EXTRA_ATTR
	{
		PLAYER_EXTRA_ATTR_INVALID = -1,

		PLAYER_EXTRA_ATTR_PLAYER_ID,

		PLAYER_EXTRA_ATTR_COUNT,
	};

	enum GUILD_MEMBER_ATTR
	{
		GUILD_MEMBER_ATTR_INVALID = -1,

		GUILD_MEMBER_ATTR_EXP,
		GUILD_MEMBER_ATTR_POWER,
		GUILD_MEMBER_ATTR_HONOR,

		GUILD_MEMBER_ATTR_COUNT,
	};

	enum MAIN_TYPE
	{
		MAIN_TYPE_INVALID = -1,

		MAIN_TYPE_MAIN,
		MAIN_TYPE_TOWER,

		MAIN_TYPE_COUNT,
	};

	enum TOWER_TYPE
	{
		TOWER_TYPE_INVALID=-1,
		TOWER_TYPE_A,
		TOWER_TYPE_B,
		TOWER_TYPE_C,
		TOWER_TYPE_D,
		TOWER_TYPE_E,
		TOWER_TYPE_COUNT,
	};

	struct TowerInfo
	{
		int		id;
		int		type;
		int		level;
		mw_base::uint64 time;

		template<typename T>
		void map(T& s)
		{
			s << id;
			s << type;
			s << level;
			s << time;
		}
	};

	struct GongFangTowerInfo 
	{
		GongFangTowerInfo():towerID(-1),towerType(0), towerLevel(0), towerTime(0) {}

		template<typename T>
		void map(T& s)
		{
			s << towerID;
			s << towerType;
			s << towerLevel;
			s << towerTime;
		}

		int towerID;
		int	towerType;
		int	towerLevel;
		long long towerTime;
	};

	enum NEWS_TYPE
	{
		NEWS_TYPE_INVLAID = -1,
		
		NEWS_TYPE_HAVE_ASK_VIGOR,
		NEWS_TYPE_HAVE_ASK_VIGOR_AGREE,
		NEWS_TYPE_HAVE_ASK_VIGOR_REJECT,
		NEWS_TYPE_HAVE_GONGFANG,			//被攻防的消息
		NEWS_TYPE_MY_BE_HIT_FINISH,			//自己被攻防站完的通知

		NEWS_TYPE_COUNT,
	};

	enum GUILD_ATTR
	{
		GUILD_ATTR_INVALID = -1,
		
		GUILD_ATTR_GOLD,
		GUILD_ATTR_DIAMOND,
		GUILD_ATTR_EXP,
		GUILD_ATTR_ATTR1,
		GUILD_ATTR_ATTR2,
		GUILD_ATTR_ATTR3,
		GUILD_ATTR_ATTR4,

		GUILD_ATTR_COUNT,
	};



	struct GuildTargetInfo 
	{
		template<typename T>
		void map(T& s)
		{
			s << guild_name;
			s << guild_id;
			s << guild_head;
			s << player_name;
			s << player_id;
			s << player_head;
			s << curr_time;
		}

		STRING_NICKNAME     guild_name;
		int 				guild_id;
		int					guild_head;
		STRING_NICKNAME		player_name;
		int 				player_id;
		STRING_HEAD_URL		player_head;
		mw_base::int64		curr_time;
	};
	struct GuildTargetRankInfo
	{
		STRING_NICKNAME     guild_name;
		int id;
		int score;
		int guild_head;
		template<typename T>
		void map(T& s)
		{
			s << guild_name;
			s << id;
			s << score;
			s << guild_head;
		}
	};

	struct GuildRankInfo
	{
		template<typename T>
		void map(T& s)
		{
			s << useID;
			s << rankID;
			s << agency;
			s << score;
			s << nickname;
			s << headurl;
		}

		int useID;
		int rankID;	// 排行id.
		char agency;	// 
		long long score;	// 分数;
		STRING_NICKNAME nickname;// 昵称
		STRING_HEAD_URL headurl; //头像;
	};

#define MAX_CARD_COUNT 20
	struct stCard {
		template<typename T>
		void map(T& s)
		{
			s << m_id;
			s << m_cardID;
			s << m_exp;
			s << m_equipexp1;
			s << m_equipexp2;
			s << m_equipexp3;
			s << m_skill1;
			s << m_skill2;
			s << m_skill3;
		}

		int					m_id;				//唯一id
		short				m_cardID;			//配置id
		int					m_exp;				//卡exp
		int					m_equipexp1;		//equip_exp1
		int					m_equipexp2;		//equip_exp2
		int					m_equipexp3;		//equip_exp3
		short				m_skill1;			//卡skill1
		short				m_skill2;			//卡skill2
		short				m_skill3;			//卡skill3
	};
}

#endif
