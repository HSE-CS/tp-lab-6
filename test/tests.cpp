// Copyright 2021 TimurZaytsev
//

#include <gtest/gtest.h>
#include <string>

#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(StaffDemoTest, test1) {
    Cleaner c(123123, "John Doe", 1000);

    EXPECT_EQ(c.calc_bonus(), 0);
}

TEST(StaffDemoTest, test2) {
    TeamLeader tl(21312321, "John Doe", 44000, { "13213", 200000 });
    tl.set_worktime(24);

    EXPECT_EQ(tl.calc_heads(), 220000);
}

TEST(StaffDemoTest, test3) {
    Tester t(21312321, "John Doe", 44000, { "13213", 200000 });
    t.set_worktime(24);

    EXPECT_EQ(t.calc_budget_part(0.1, 100000), 10000);
}

TEST(StaffDemoTest, test4) {
    Cleaner c(123123, "John Doe", 1000);

    EXPECT_EQ(c.calc_base(24, 2000), 2000);
}

TEST(StaffDemoTest, test5) {
    Driver d(123123, "John Doe", 1000);

    EXPECT_EQ(d.calc_base(1000, 12), 600);
}

TEST(StaffDemoTest, test6) {
    SeniorManager sm(21312321, "John Doe",
        { {"13213", 200000}, {"343213", 123213} });

    EXPECT_EQ(sm.calc_heads(), 50000);
}

TEST(StaffDemoTest, test7) {
    Tester t(21312321, "John Doe", 44000, { "13213", 200000 });

    EXPECT_EQ(t.calc_base(1000, 12), 600);
}

TEST(StaffDemoTest, test8) {
    Tester t(21312321, "John Doe", 44000, { "13213", 200000 });
    t.set_worktime(24);

    EXPECT_EQ(t.calc_bonus(), 0);
}

TEST(StaffDemoTest, test9) {
    Tester t(21312321, "John Doe", 44000, { "13213", 200000 });
    t.set_worktime(24);

    EXPECT_EQ(t.calc_pro_additions(), 10560);
}

TEST(StaffDemoTest, test10) {
    Programmer p(21312321, "John Doe", 44000, { "13213", 200000 });
    p.set_worktime(24);

    EXPECT_EQ(p.calc_pro_additions(), 18333);
}

TEST(StaffDemoTest, test11) {
    ProjectManager pm(21312321, "John Doe", { "13213", 200000 });
    pm.set_worktime(24);

    EXPECT_EQ(pm.calc_heads(), 50000);
}

TEST(StaffDemoTest, test12) {
    Driver d(123123, "John Doe", 1000);
    d.set_worktime(10);

    EXPECT_EQ(d.calc_bonus(), 100);
}
