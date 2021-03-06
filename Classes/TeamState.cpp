#include "header.h"
#include "ConstVar.h"
#include "TeamState.h"
#include "rapidjson\document.h"
#include <fstream>
#include "Player.h"
USING_NS_CC;

TeamState::TeamState() :
	m_homeTeam(),
	m_awayTeam(),
	m_homeFielder(),
	m_awayFielder(),
	m_curFielder(),
	m_homeBatList(),
	m_awayBatList(),
	m_curBatList(),
	m_homePitcher(nullptr),
	m_awayPitcher(nullptr),
	m_curPitcher(nullptr),
	m_curBatter(nullptr)
{
}

TeamState::~TeamState()
{
}

void TeamState::SetSampleList()
{
	if (*m_homeTeam || *m_awayTeam){
		throw "already setted";
		return;
	}

	auto path = FileUtils::getInstance()->fullPathForFilename("sample.json");
	ssize_t size;
	auto str = FileUtils::getInstance()->getFileData(path, "r", &size);

	auto is = std::ifstream(path, std::ifstream::in);
	char buffer[65536] = { 0, };
	is.read(buffer, 65536);

	rapidjson::Document d;
	d.Parse(buffer);

	assert(d.IsObject());
	const auto& teamA = d["teamA"];
	m_teamNameA = teamA["name"].GetString();
	assert(m_teamNameA == ConstVar::SAMPLE_AWAYNAME);
	for (int i = 0; i < 25; i++ )
	{
		const auto& player = teamA["players"][i];
		assert(player.IsObject());
		std::string name = player["name"].GetString();
		int batELO = player["batELO"].GetInt();
		int pitELO = player["pitELO"].GetInt();
		m_awayTeam[i] = new Player(i, name, batELO, pitELO);
	}

	const auto& teamH = d["teamB"];
	m_teamNameH = teamH["name"].GetString();
	assert(m_teamNameH == ConstVar::SAMPLE_HOMENAME);
	for (int i = 0; i < 25; i++)
	{
		const auto& player = teamH["players"][i];
		assert(player.IsObject());
		std::string name = player["name"].GetString();
		int batELO = player["batELO"].GetInt();
		int pitELO = player["pitELO"].GetInt();
		m_homeTeam[i] = new Player(i, name, batELO, pitELO);
	}
}

Player* TeamState::GetPlayer(std::string teamName, int idx)
{
	if (teamName == m_teamNameA)
	{
		Player* p = m_awayTeam[idx];
		return p;
	}
	else if (teamName == m_teamNameH)
	{
		Player* p = m_homeTeam[idx];
		return p;
	}
}