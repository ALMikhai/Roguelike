#include "Settings.h"

rapidjson::Document Load() {
  FILE *fp = fopen("../Models/Settings/Settings.json", "r");
  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  rapidjson::Document doc;
  doc.ParseStream(is);
  fclose(fp);
  return doc;
}

namespace Settings{
extern const rapidjson::Document settingsData(Load());
}