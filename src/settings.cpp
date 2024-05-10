#include <settings.hpp>

Settings settings()
{
    Settings settings;
    char delim;
    string information, data_type, parameter;
    int information_counter = 0;
    int data_type_counter = 0;
    int parameter_counter = 0;
    bool is_first_parameter = true;
    bool is_first_data_type = true;
    ifstream settings_stream(SETTINGS_PATH + "settings.txt");
    while (getline(settings_stream, information))
    {
        data_type_counter = 0;
        stringstream information_stream(information);
        if (information_counter == 0 || information_counter == 1)
            delim = FIRST_DELIM;
        else delim = THIRD_DELIM;
        while (getline(information_stream, data_type, delim))
        {
            if (is_first_data_type && (information_counter == 2 ||
                information_counter == 3))
            {
                is_first_data_type = false;
                continue;
            }
            parameter_counter = 0;
            stringstream data_type_stream(data_type);
            while (getline(data_type_stream, parameter, SECOND_DELIM))
            {
                if (is_first_parameter && (information_counter == 0 ||
                    information_counter == 1))
                {
                    is_first_parameter = false;
                    continue;
                }
                switch (information_counter)
                {
                case 0:
                    switch (data_type_counter)
                    {
                    case 0:
                        settings.Zombie.push_back(stof(parameter));
                        break;
                    case 1:
                        settings.Titan.push_back(stof(parameter));
                        break;
                    default:
                        break;
                    }
                    break;
                case 1:
                    switch (data_type_counter)
                    {
                    case 0:
                        settings.Peashooter.push_back(stof(parameter));
                        break;
                    case 1:
                        settings.SnowPeashooter.push_back(stof(parameter));
                        break;
                    case 2:
                        settings.Sunflower.push_back(stof(parameter));
                        break;
                    case 3:
                        settings.Wallnut.push_back(stof(parameter));
                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    settings.Attack.push_back(stof(parameter));
                    break;
                case 3:
                    settings.Sun.push_back(stof(parameter));
                    break;
                default:
                    break;
                }
                parameter_counter++;
            }
            is_first_parameter = true;
            data_type_counter++;
        }
        is_first_data_type = true;
        information_counter++;
    }
    settings_stream.close();
    return settings;
}