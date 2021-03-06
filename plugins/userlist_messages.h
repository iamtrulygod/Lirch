#ifndef USERLIST_MESSAGES_H_
#define USERLIST_MESSAGES_H_

#include <unordered_map>
#include <QtCore/QString>

#include "core/message.h"
#include "user_status.h"

class userlist_message : public message_data
{
public:
	virtual std::unique_ptr<message_data> copy() const {return std::unique_ptr<message_data>(new userlist_message(*this));}
	static message create(const std::unordered_map<QString, user_status> &m) {return message_create("userlist", new userlist_message(m));}

	userlist_message(const std::unordered_map<QString, user_status> &m) : statuses(m) {}

	std::unordered_map<QString, user_status> statuses;
};

class userlist_request : public message_data
{
public:
	virtual std::unique_ptr<message_data> copy() const {return std::unique_ptr<message_data>(nullptr);}
	static message create() {return message_create("userlist_request", nullptr);}
};

#endif
