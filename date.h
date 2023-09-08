class Date {
    public:

        Date(){
            this->month = 0;
            this->day = 0;
            this->year = 0;
        }
        // Sets the release date for a movie
        Date(int dateMonth, int dateDay, int dateYear) {
            month = dateMonth;
            day = dateDay;
            year = dateYear;
        }
        int GetMonth() {
            return month;
        }
        int GetDay() {
            return day;
        }
        int GetYear() {
            return year;
        }
        void SetMonth(int tempMonth) {
            month = tempMonth;
        }
        void SetDay(int tempDay) {
            day = tempDay;
        }
        void SetYear(int tempYear) {
            year = tempYear;
        }
        // Checks if movie's release date is less than given date
        bool isLessThan(Date date) {
            if (this->year < date.GetYear()) {
                return true;
            }
            else {
                if (this->year == date.GetYear()) {
                    if (this->month < date.GetMonth()) {
                        return true;
                    }
                    else {
                        if (this->month == date.GetMonth()) {
                            if (this->day < date.GetDay()) {
                                return true;
                            }
                        }
                    }
                }
            }
            return false;
        }
    private:
        int month, day, year;
};