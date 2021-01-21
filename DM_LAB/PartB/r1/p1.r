

dt <- read.csv("melanoma.csv",header = TRUE)

is.na(dt)

head(dt)

list_na <- colnames(dt)[apply(dt, 2, anyNA)]

list_na

dt$age = ifelse(is.na(dt$age),ave(dt$age,FUN = function(x) mean(x,na.rm = 'TRUE')),dt$age)

dt$time = ifelse(is.na(dt$time),ave(dt$time,FUN = function(x) mean(x,na.rm='TRUE')),dt$time)
dt$sex = ifelse(is.na(dt$sex),ave(dt$sex,FUN=function(x) mean(x,na.rm='TRUE')),dt$sex)

summary(dt)

log(dt)

summary(log(dt))

#drop column
dt = subset(dt, select = -c(time))
dt = subset(dt, select = -c(year))

cor(dt)

cor(dt$sex,dt$age)
cor(dt$thickness,dt$ulcer)

#rounding off floating values
dt$age = as.numeric(format(round(dt$age, 0)))
dt$sex = as.numeric(format(round(dt$sex, 0)))

#catogarical values
dt$sex = factor(dt$sex, levels = c(1,0),  labels = c('M','F'))
dt$sex = factor(dt$sex, levels = c('M','F'),  labels = c(1,0))
