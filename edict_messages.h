#ifndef EDICT_MESSAGES_H_
#define EDICT_MESSAGES_H_

#include <QString>

#include "message.h"

class raw_edict_message : public message_data
{
public:
	virtual std::unique_ptr<message_data> copy() const {return std::unique_ptr<message_data>(new raw_edict_message(*this));}
	static message create(const QString &c) {return message_create("raw_edict", new raw_edict_message(c));}

	raw_edict_message(const QString &c) : contents(c) {}

	QString contents;
};

class edict_message : public message_data
{
public:
	virtual std::unique_ptr<message_data> copy() const {return std::unique_ptr<message_data>(new edict_message(*this));}
	static message create(const QString &c) {return message_create("edict", new edict_message(c));}

	edict_message(const QString &c) : contents(c) {}

	QString contents;
};

class me_edict_message : public message_data
{
public:
	virtual std::unique_ptr<message_data> copy() const {return std::unique_ptr<message_data>(new me_edict_message(*this));}
	static message create(const QString &c) {return message_create("me_edict", new me_edict_message(c));}

	me_edict_message(const QString &c) : contents(c) {}

	QString contents;
};

#endif
